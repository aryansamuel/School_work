//--------------------------------------------------------------------------------------------------------
// FileReverse.java
// Aryan Samuel
// arsamuel
// CMPS 12M
// 04/09/16
// Lab 2
// Takes input from a file, parses the tokens, and prints them out backwards each in a separate line.
//--------------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class FileReverse {
	
	public static void main (String[] args) throws IOException{
		
		Scanner in = null;
		PrintWriter out = null;
		String line = null;
		String[] token = null;
		int n;
		
		// Check CL argument length
		if (args.length < 2) {
			System.out.println("Usage: FileReverse <input file> <output file>");
			System.exit(1);
		}
		
		// Open files
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		
		// Read lines from in and write to out
		while (in.hasNextLine()) {
			line = in.nextLine().trim() + " ";
			token = line.split("\\s+");
			for (int i=0; i<token.length; i++) {
				out.println(stringReverse(token[i], token[i].length()));
			}
		}
		
		// Close files
		in.close();
		out.close();
	}
	
	public static String stringReverse(String s, int n) {
		String S = "";
		if (n>0) {
			S = s.charAt(n-1)+stringReverse(s,n-1);
		} return S;
	} 
	
}
