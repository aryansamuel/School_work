//--------------------------------------------------------------------------------------------------------
// Lex.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/01/16
// Programming Assignment 1
// Takes in an input from a user specified input file, alphabetizes its contents, and prints 
// the output to a user specified output file.
//--------------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class Lex {
	
	public static void main (String[] args) throws IOException{
		
		Scanner in = null;
		PrintWriter out = null;
		int i, n = 0;
		
		// Error Check
		if ( (args.length < 2) || (args.length > 2) ) {
			System.err.println("Usage: Lex infile outfile");
			System.exit(1);
		}
		
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		
		// Number of lines
		while (in.hasNextLine()) {
			in.nextLine();
			n++;
		}
		
		// Put elements in string arry
		String[] words = new String[n];
		in = new Scanner(new File(args[0]));
		for (int k=0; k<n; k++) {
			words[k] = in.nextLine();
		}
		
		// Create new List
		List L = new List();
		L.append(0);
		
		// Lex Algorithm
		for (int j=1; j<n; j++) {
			String s = words[j];
			i = j-1;
			L.moveBack(); // Move cursor to the end
			while (i >= 0 && (s.compareTo(words[L.get()]) < 0) ) { // Compare words to cursor word
				L.movePrev(); // Move cursor one step back
				i--;
			}
			if (L.index() == -1) L.prepend(j); // If cursor is null, insert j as first element
			else L.insertAfter(j); // Otherwise insert after where cursor stopped
		}
				
		// Print to output file
		L.moveFront();
		for (int k=0; k<n; k++) {
			out.println(words[L.get()]);
			L.moveNext();
		}
		
		in.close();
		out.close();
	}
}
		