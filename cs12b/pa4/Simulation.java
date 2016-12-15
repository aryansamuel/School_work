//--------------------------------------------------------------------------------------------------
// Simulation.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 05/11/16
// Programming Assignment 4
// Program that simulates a set of jobs performed by processors. Output files include:
//   input_file.rpt -> Contains the results total wait, max wait, and avg wait for n processors.
//   input_file.trc -> Contains detailed trace of the states of the simulation.
//--------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class Simulation {
	
	// Main function
	public static void main (String[] args) throws IOException {
		Scanner in = null;
		PrintWriter report = null;
		PrintWriter trace = null;
		int m, n, sq=50, time=-1, maxWait=0;
		float totalWait=0, avgWait=0;
		int[] waitTime;
		
		// Open files
		in = new Scanner(new File(args [0]));
		report = new PrintWriter(new FileWriter(args[0] + ".rpt"));
		trace = new PrintWriter(new FileWriter(args[0] + ".trc"));
		// File headers
		report.println("Report file: " + args[0] + ".rpt");
		trace.println("Trace file: " + args[0] + ".trc");
		
		// Declare m Jobs and n processors, and Queues
		m = in.nextInt();
		n = m-1;
		waitTime = new int[m];
		in.nextLine(); // Return to next line in file
		Queue[] jobQ = new Queue[n+1];
		Queue[] dataQ = new Queue[n+1];
		Queue dupQ = new Queue();
		Queue strgQ = new Queue();
		for (int i=0; i<m; i++) {
			strgQ.enqueue(getJob(in));
		}
		
		// File print statements
		report.println(m + " Jobs:");
		report.println(strgQ);
		report.println();
		trace.println(m + " Jobs:");
		trace.println(strgQ);
		trace.println();
		
		
		// Run Simulation
		for (n=1; n<=m-1; n++) {
			
			// Declare Queue array and Storage queues
			for (int i=1; i<=n; i++) {
				jobQ[i] = new Queue();
			}
			
			// Trace print statements
			trace.println("*****************************");
			trace.println(n + " processor" + ((n>1) ? "s:" : ":"));
			trace.println("*****************************");
			trace.println("time=0");
			trace.println("0: " + strgQ);
			for (int i=1; i<=n; i++) {
				trace.println(i + ": " + jobQ[i]);
			}
			trace.println();
			
			time = -1; // Reset time
			
			// While unporccessed jobs remain
			while( (strgQ.isEmpty()) || ( (((Job)strgQ.peek()).getFinish()) == -1) || (chkQ(jobQ, n)==false) ) {
				
				time++;
				
				while ( (!strgQ.isEmpty()) && ( (((Job)strgQ.peek()).getArrival()) == time) ) {
					sq = (smallQ(jobQ, n));
					jobQ[sq].enqueue(((Job)strgQ.peek()));
					strgQ.dequeue();
					if ( (((Job)jobQ[sq].peek()).getFinish()) == -1 ) {
						((Job)jobQ[sq].peek()).computeFinishTime(time);
					}
					// Trace print statements
					trace.println("time=" + time);
					trace.println("0: " + strgQ);
					for (int i=1; i<=n; i++) {
						trace.println(i + ": " + jobQ[i]);
					}
					trace.println();
				} for (int i=1; i<=n; i++) {
					while ( (!jobQ[i].isEmpty()) && ( ((Job)jobQ[i].peek()).getFinish() == time ) ) {
						strgQ.enqueue(jobQ[i].peek());
						jobQ[i].dequeue();
						if (!jobQ[i].isEmpty()) {
							((Job)jobQ[i].peek()).computeFinishTime(time);
						}
						// Trace print statements
						trace.println("time=" + time);
						trace.println("0: " + strgQ);
						for (int j=1; j<=n; j++) {
							trace.println(j + ": " + jobQ[j]);
						}
						trace.println();
					}
				}
			}

			// Create duplicate Array queue to calculate data
			
			for (int i=0; i<m; i++) {
				dataQ[i] = new Queue();
				dataQ[i].enqueue(strgQ.peek());
				dupQ.enqueue(strgQ.peek());
				strgQ.dequeue();
			}

			// Create array of Wait times
			for (int i=0; i<m; i++) {
				waitTime[i] = ((Job)dataQ[i].peek()).getFinish() - ((Job)dataQ[i].peek()).getArrival() - ((Job)dataQ[i].peek()).getDuration();
			}
			// Total Wait time
			for (int i=0; i<m; i++) {
				totalWait = totalWait + waitTime[i];
			}
			// Max Wait
			for (int i=0; i<m; i++) {
				if (waitTime[i] > maxWait) {
					maxWait = waitTime[i];
				}
			}
			// Average wait
			avgWait = totalWait/m;
			
			// Print Report
			report.print(n + " processor" + ((n>1) ? "s: " : ": ") + "totalWait=" + totalWait + ", maxWait=" + maxWait + ", ");
			report.printf("averageWait=%.2f\n",avgWait);
			
			// Reset Finish times and other values
			for (int i=0; i<m; i++) {
				((Job)dupQ.peek()).resetFinishTime();
				strgQ.enqueue(dupQ.peek());
				dupQ.dequeue();
			}
			totalWait = 0;
			maxWait = 0;
			avgWait = 0;
		}
		
		// Close files
		in.close();
		report.close();
		trace.close();
	}
	
	
	// getJob() function
	public static Job getJob (Scanner in) {
		String[] s = in.nextLine().split(" ");
		int a = Integer.parseInt(s[0]);
		int d = Integer.parseInt(s[1]);
		return new Job(a, d);
	}
	
	// smallQ() -> evaluates the index of the smallest Queue
	public static int smallQ (Queue[] s, int p) {
		int min=s[1].length(), x=0;
		for (int i=1; i<=p; i++) {
			if (s[i].length() <= min) {
				min = s[i].length();
			}
		}
		for (int i=1; i<=p; i++) {
			if (s[i].length() == min) {
				x = i;
				break;
			}
		}
		return x;
	}
	
	// chkQ -> checks if all queues are empty
	public static boolean chkQ (Queue[] s, int p) {
		int num=0;
		for (int i=1; i<=p; i++) {
			num = num + s[i].length();
		}
		if (num == 0) return true;
		else return false;
	}
}