//--------------------------------------------------------------------------------------------------------
// Matrix.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/22/16
// Programming Assignment 3
// Matrix ADT that is implemented by Sparse.java. Does basic Matrix operations such as copying,
// adding, subtracting, transposing, and multiplying two matrices.
//--------------------------------------------------------------------------------------------------------

class Matrix {
	
	// Private inner Entry class
	private class Entry {
		int col;
		double value;
		
		// Constructor
		Entry(int col, double value) {
			this.col = col;
			this.value = value;
		}
		
		// toString()
		public String toString() {
			return "(" + col + ", " + value + ")";
		}
		
		// equals()
		public boolean equals(Object x) {
			boolean eq = false;
			Entry E;
			
			if(x instanceof Entry) {
				E = (Entry)x;
				eq = (this.col == E.col) && (this.value == (E.value));
			}
			return eq;
		}
	}
	
	// Constructor
	List[] row;
	Matrix (int n) {
		if (n < 1) {
			throw new RuntimeException("Matrix Error: Matrix() called on invalid column number.");
		}
		row = new List[n+1];
		makeZero();
	}
	
	
	// Access Functions ----------------------------------------------------------------------------
	
	// getSize()
	// Returns n, the number of rows and columns of this Matrix.
	int getSize() {
		return row.length-1;
	}
	
	// getNNZ()
	// Returns the number of non-zero entries in this Matrix.
	int getNNZ() {
		int i=0;
		for(int j=1; j<=getSize(); j++) {
			i = i + row[j].length();
		}
		return i;
	}
	
	// equals()
	// Returns true if this Matrix and M are the same sequence.
	public boolean equals (Object x) {
		boolean eq = false;
		Matrix A = (Matrix)x;

		for (int i=1; i<=getSize(); i++) {
			if (this.row[i] == A.row[i]) {
				eq = true;
			}
			else eq = false;
		}
		return eq;
	}
	
	
	// Manipulation Procedures ---------------------------------------------------------------------
	
	// makeZero()
	// Sets this Matrix to the zero state.
	void makeZero() {
		for (int i=1; i<=getSize(); i++) {
			row[i] = new List();
		}
	}
	
	// copy()
	// Returns a new Matrix having the same entries as this Matrix.
	Matrix copy() {
		Matrix M = new Matrix(getSize());
		for (int i=1; i<=getSize(); i++) {
			row[i].moveFront();
			while (row[i].index() >= 0) {
				Entry E = (Entry)row[i].get();
				M.changeEntry(i, E.col, E.value);
				row[i].moveNext();
			}
		}
		return M;
	}

	// changeEntry()
	// changes ith row, jth column of this Matrix to x
	// pre: 1<=i<=getSize(), 1<=j<=getSize().
	void changeEntry (int i, int j, double x) {
		if (i<1 || i>getSize()) {
			throw new RuntimeException("Matrix Error: changeEntry() called on invalid row.");
		}
		if (j<1 || j>getSize()) {
			throw new RuntimeException("Matrix Error: changeEntry() called on invalid column.");
		}
		
		Entry N = new Entry(j, x);
		int k = 1;
		
		if (row[i].length() == 0) { // If list is empty and x != 0
			if (x != 0) {
				row[i].append(N);
			}
		} else if (row[i].length() == 1) { // if List has one value
			if (x == 0) {
				row[i].moveFront();
				if (row[i].index() == -1) {
					row[i].delete();
				}
			} else {
				row[i].moveFront();
				Entry E = (Entry)row[i].get();
				if (j < E.col) {
					row[i].prepend(N);
				} else if (j == E.col) {
					E.value = x;
				} else {
					row[i].append(N);
				}
			}
		} else if (row[i].length() > 1) { //if list has more than one value
			row[i].moveFront();
		
			while (k<j) {
				row[i].moveNext();
				k++;
			}
			if (x == 0) {
				if (row[i].index() != -1) {
					row[i].delete();
				}
			} else { //if x != 0
				boolean b = true;
				row[i].moveFront();
				while (b) {
					Entry E = (Entry)row[i].get();
					if (j < E.col) {
						row[i].insertBefore(N);
						b = false;
					} else if (j == E.col) {
						E.value = x;
						b = false;
					} else { //if j>E.col
						row[i].moveNext();
						if (row[i].index() == -1) {
							row[i].append(N);
							b = false;
						}
					}
				}
			}
		}
	}
	
	// scalarMult
	// Returns a new Matrix that is the scalar product of this Matrix with x.
	Matrix scalarMult (double x) {
		Matrix B = copy();
		Entry E;
		for (int i=1; i<=getSize(); i++) {
			B.row[i].moveFront();
			for (int j=1; j<=row[i].length(); j++) {
				E = (Entry)B.row[i].get();
				B.changeEntry(i, j, E.value*x);
				B.row[i].moveNext();
			}
		}
		return B;
	}
	
	// add()
	// Returns a new Matrix that is the sum of this Matrix with M
	// pre: getSize() == M.getSize().
	Matrix add (Matrix M) {
		if (getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: add() called on Matrices with different sizes.");
		}
		
		Matrix N = new Matrix(getSize());
		if (this == M) {
			N = M.scalarMult(2);
			return N;
		}
		
		for (int i=1; i<=getSize(); i++) {
			List L = new List();
			M.row[i].moveFront();
			this.row[i].moveFront();
			
			while (this.row[i].index() >=0 || M.row[i].index() >=0) {
				if (this.row[i].index() >=0 && M.row[i].index() >=0) {
					Entry E = (Entry)this.row[i].get();
					Entry F = (Entry)M.row[i].get();
					
					if (E.col > F.col) {
						L.append(new Entry(F.col, F.value));
						M.row[i].moveNext();
					} else if (E.col == F.col) {
						//System.out.println("Hello");
						if (E.value + F.value != 0) {
							L.append(new Entry(E.col, E.value + F.value));
						}
						M.row[i].moveNext();
						this.row[i].moveNext();
					} else if (E.col < F.col) {
						L.append(new Entry(E.col, E.value));
						this.row[i].moveNext();
					}
				} else if (this.row[i].index() >= 0) {
					Entry E = (Entry)this.row[i].get();
					L.append(new Entry(E.col, E.value));
					this.row[i].moveNext();
				} else {
					Entry F = (Entry)M.row[i].get();
					L.append(new Entry(F.col, F.value));
					M.row[i].moveNext();
				}
			}
			N.row[i] = L;
		}
		return N;
	}
	
	// sub()
	// Returns a new matrix that is the difference of this Matrix with M
	// pre: getSize() == M.getSize().
	Matrix sub (Matrix M) {
		if (getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: add() called on Matrices with different sizes.");
		}
		
		Matrix N = new Matrix(getSize());
		if (this == M) {
			N = new Matrix(getSize());
			return N;
		}
		
		for (int i=1; i<=getSize(); i++) {
			List L = new List();
			M.row[i].moveFront();
			this.row[i].moveFront();
			
			while (this.row[i].index() >=0 || M.row[i].index() >=0) {
				if (this.row[i].index() >=0 && M.row[i].index() >=0) {
					Entry E = (Entry)this.row[i].get();
					Entry F = (Entry)M.row[i].get();
					
					if (E.col > F.col) {
						L.append(new Entry(F.col, -F.value));
						M.row[i].moveNext();
					} else if (E.col == F.col) {
						if (E.value - F.value != 0) {
							L.append(new Entry(E.col, E.value - F.value));
						}
						M.row[i].moveNext();
						this.row[i].moveNext();
					} else if (E.col < F.col) {
						L.append(new Entry(E.col, E.value));
						this.row[i].moveNext();
					}
				} else if (this.row[i].index() >= 0) {
					Entry E = (Entry)this.row[i].get();
					L.append(new Entry(E.col, E.value));
					this.row[i].moveNext();
				} else {
					Entry F = (Entry)M.row[i].get();
					L.append(new Entry(F.col, -F.value));
					M.row[i].moveNext();
				}
			}
			N.row[i] = L;
		}
		return N;
	}
	
	// transpose()
	// Returns a new Matrix that is the transpose of this Matrix.
	Matrix transpose() {
		Matrix N = new Matrix(getSize());
		for (int i=1; i<=getSize(); i++) {
			row[i].moveFront();
			while (row[i].index() >= 0) {
				Entry E = (Entry)row[i].get();
				Entry F = (Entry)row[i].get();
				N.changeEntry(E.col, i, F.value);
				row[i].moveNext();
			}
		}
		return N;
	}
	
	// mult()
	// Returns a new Matrix that is the product of this Matrix with M
	// pre: getSize() == M.getSize()
	Matrix mult (Matrix M) {
		if (getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: mult() called on Matrices with different sizes.");
		}
		
		Matrix N = new Matrix(getSize());
		Matrix T = M.transpose();
		
		for (int i=1; i<=getSize(); i++) {
			if (row[i].length() != 0) {
				for (int j=1; j<=getSize(); j++) {
					if (T.row[j].length() != 0) {
						N.changeEntry(i, j, dot(row[i], T.row[j]));
					}
				}
			}
		}
		
		return N;
	}
	
	
	// Other Functions -----------------------------------------------------------------------------
	
	// dot()
	// Computes the vector dot product of two matrix rows represented my Lists P and Q.
	private static double dot (List P, List Q) {
		double x = 0;
		P.moveFront();
		Q.moveFront();
		while (P.index() >=0 && Q.index() >= 0) {
			Entry E = (Entry)P.get();
			Entry F = (Entry)Q.get();
			if (E.col > F.col) {
				Q.moveNext();
			} else if (E.col < F.col) {
				P.moveNext();
			} else {
				x = x + (E.value * F.value);
				P.moveNext();
				Q.moveNext();
			}
		}
		return x;
	}
		
	
	// toString()
	// Overrides Object's toString() method.
	public String toString() {
		StringBuffer sb = new StringBuffer();
		Entry E;
		double z;
		if (getNNZ() != 0) {
			for (int i=1; i<=getSize(); i++) {
				if (row[i].length() > 0) {
					sb.append(i + ": " + row[i]);
					if (i < getSize()) {
						sb.append("\n");
					}
				}
			}
			return new String(sb);
		} else return "";
	}
	
}