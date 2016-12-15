//--------------------------------------------------------------------------------------------------------
// Sparse.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/22/16
// Programming Assignment 3
// Takes input from a file and creates two matrices to perform functions on.
//--------------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class Sparse {
	
	public static void main (String[] args) throws IOException {
		
		Scanner in = null;
		PrintWriter out = null;
		
		// Error check
		if ( (args.length < 2) || (args.length > 2) ) {
			System.err.println("Usage: Sparse infile outfile");
			System.exit(1);
		}
		
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		
		String[] vars = new String[3];
		for (int i=0; i<3; i++) {
			vars[i] = in.next();
		}
		
		int rows = Integer.parseInt(vars[0]);
		int Annz = Integer.parseInt(vars[1]);
		int Bnnz = Integer.parseInt(vars[2]);
		
		Matrix A = new Matrix(rows);
		Matrix B = new Matrix(rows);
		
		// Read in values for Matrix A
		for (int i=1; i<=Annz; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			double z = in.nextDouble();
			A.changeEntry(x, y, z);
		}
		
		// Read in values for Matrix B
		for (int i=1; i<=Bnnz; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			double z = in.nextDouble();
			B.changeEntry(x, y, z);
			//in.nextLine();
		}
		
		
		// Outputs------------------------------------------------------------------------
		
		// Non-zero entires along with Matrices
		out.println("A has " + Annz + " non-zero entries:");
		out.println(A + "\n");
		out.println("B has " + Bnnz + " non-zero entries:");
		out.println(B + "\n");
		
		// (1.5)*A
		out.println("(1.5)*A =");
		out.println(A.scalarMult(1.5) + "\n");
		
		// A+B
		out.println("A+B =");
		out.println(A.add(B) + "\n");
		
		// A+A
		out.println("A+A =");
		out.println(A.add(A) + "\n");
		
		// B-A
		out.println("B-A =");
		out.println(B.sub(A) + "\n");
		
		// A-A
		out.println("A-A =");
		out.println(A.sub(A) + "\n");
		
		// Transpose(A);
		out.println("Transpose(A) =");
		out.println(A.transpose() + "\n");
		
		// A*B
		out.println("A*B =");
		out.println(A.mult(B) + "\n");
		
		// B*B
		out.println("B*B =");
		out.println(B.mult(B));
		
		
		// close files
		in.close();
		out.close();
	}
}
			