//--------------------------------------------------------------------------------------------------------
// MatrixTest.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/22/16
// Programming Assignment 3
// Test client for the Matrix ADT.
//--------------------------------------------------------------------------------------------------------

public class MatrixTest {
	public static void main (String[] args) {
		
		Matrix A = new Matrix(3);
		Matrix B = new Matrix(3);
		
		
		for (int i=1; i<=3; i++) {
			A.changeEntry(1, i, i);
			B.changeEntry(1, i, i+1);
		}
		for (int i=1; i<=3; i++) {
			A.changeEntry(2, i, i+3);
			B.changeEntry(2, i, i+4);
		}
		for (int i=1; i<=3; i++) {
			A.changeEntry(3, i, i+6);
			B.changeEntry(3, i, i+7);
		}

		System.out.println(A);
		System.out.println(B);
		
		System.out.println(A.getSize());
		System.out.println(A.getNNZ());
		
		System.out.println(A.equals(B));
		System.out.println(A.equals(A));
		
		Matrix C = A.copy();
		System.out.println(C);
		System.out.println();
		
		// Test each function out one by one by uncommenting.
		
		// Here for easier comparison
		/*System.out.println(A);
		System.out.println();
		System.out.println(B);
		System.out.println();*/
		
		//A.scalarMult(2);
		//System.out.println(A.add(B));
		//System.out.println(A.sub(B));
		//System.out.println(B.transpose());
		//System.out.println(A.mult(B));
		
		A.makeZero();
		System.out.println(A.getNNZ());
	}
}