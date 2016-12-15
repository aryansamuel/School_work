//---------------------------------------------------------------------------------------------------
// Dictionary.java
// Aryan Samuel
// arsamuel
// CMPS 12M
// 06/27/16
// Lab 7
// A Dictionary ADT based on Binary Search Trees. 
// Consits of pairs of Strings called Keys and Values. 
// Performs various functions such as creating and deleting a Dictionary, 
// and inserting, finding, or removing specific items to and fromt it.
//---------------------------------------------------------------------------------------------------

public class Dictionary implements DictionaryInterface {
	
	// Private Types & Functions ----------------------------------------------------------------
	
	// Private Node class
	private class Node {
		String key;
		String value;
		Node left;
		Node right;
		
		Node (String x, String y) {
			key = x;
			value = y;
			left = null;
			right = null;
		}
	}
	
	// Fields for Dictionary class
	private Node root;
	private int numPairs;
	
	// Dictionary()
	public Dictionary() {
		root = null;
		numPairs = 0;
	}
	
	// findKey()
	// returns the Node containing key k in the subtree rooted at R, or returns
	// NULL if no such Node exists
	private Node findKey (Node N, String k) {
		if (N==null || N.key.equals(k)) {
			return N;
		} if (k.compareTo(N.key) < 0) {
			return findKey(N.left, k);
		} else {
			return findKey(N.right, k);
		}
	}
	
	// findParent()
	// returns the parent of N in the subtree rooted at R, or returns NULL
	// if N is equal to R.
	// pre: R != NULL
	private Node findParent (Node N, Node R) {
		Node P = null;
		if (N != R) {
			P = R;
			while (P.left!=N && P.right!=N) {
				if (N.key.compareTo(P.key) < 0) {
					P = P.left;
				} else {
					P = P.right;
				}
			}
		}
		return P;
	}
	
	// findLeftmost()
	// returns the leftmost Node in the subtree rooted at R, or NULL if R is NULL.
	private Node findLeftmost (Node N) {
		Node L = N;
		if (L!=null) for (; L.left!=null; L=L.left);
		return L;
	}
	
	// printInOrder()
	// prints the (key, value) pairs belonging to the subtree rooted at R in order
	// of increasing keys to file pointed to by out.
	private void printInOrder (Node N) {
		if (N != null) {
			printInOrder(N.left);
			System.out.println(N.key + " " + N.value);
			printInOrder(N.right);
		}
	}
	
	// deleteAll()
	// deletes all Nodes in the subtree rooted at N
	private void deleteAll (Node N) {
		if (N != null) {
			deleteAll(N.left);
			deleteAll(N.right);
		}
	}
	
	
	// Public functions ----------------------------------------------------------------------
	
	// isEmpty()
    // pre: none
    // returns true if this Dictionary is empty, false otherwise
    public boolean isEmpty() {
		return(numPairs == 0);
	}

    // size()
    // pre: none
    // returns the number of entries in this Dictionary
    public int size() {
		return numPairs;
	}

    // lookup()
    // pre: none
    // returns value associated key, or null reference if no such key exists
    public String lookup(String key) {
		Node N;
		N = findKey(root, key);
		return (N==null ? null : N.value);
	}

    // insert()
    // inserts new (key,value) pair into this Dictionary
    // pre: lookup(key)==null
    public void insert(String key, String value) throws DuplicateKeyException {
		Node N, A, B;
		if (findKey(root, key) != null) {
			throw new DuplicateKeyException("Dictionary Error: (" + key + ", " + value + ") already exists");
		}
		N = new Node(key, value);
		B = null;
		A = root;
		while (A != null) {
			B = A;
			if (key.compareTo(A.key) < 0) A = A.left;
			else A = A.right;
		}
		if (B == null) root = N;
		else if (key.compareTo(B.key) < 0) B.left = N;
		else B.right = N;
		numPairs++;
	}

    // delete()
    // deletes pair with the given key
    // pre: lookup(key)!=null
    public void delete(String key) throws KeyNotFoundException {
		Node N, P, S;
		N = findKey(root, key);
		if (N == null) {
			throw new KeyNotFoundException("Dictionary Error: delete() called on nonexistent key: " + key);
		}
		
		if (N.left==null && N.right==null) {
			if (N == root) {
				root = null;
			} else {
				P = findParent(N, root);
				if (P.right == N) P.right = null;
				else P.left = null;
			}
		} else if (N.right == null) {
			if (N == root) {
				root = N.left;
			} else {
				P = findParent(N, root);
				if (P.right == N) P.right = N.left;
				else P.left = N.left;
			}
		} else if (N.left == null) {
			if (N == root) {
				root = N.right;
			} else {
				P = findParent(N, root);
				if (P.right == N) P.right = N.right;
				else P.left = N.right;
			}
		} else {
			S = findLeftmost(N.right);
			N.key = S.key;
			N.value = S.value;
			P = findParent(S, N);
			if (P.right == S) P.right = S.right;
			else P.left = S.right;
		}
		numPairs--;
	}

    // makeEmpty()
    // pre: none
    public void makeEmpty() {
		deleteAll(root);
		root = null;
		numPairs = 0;
	}

    // toString()
    // returns a String representation of this Dictionary
    // overrides Object's toString() method
    // pre: none
    public String toString() {
		Node N = root;
		StringBuffer sb = new StringBuffer();
		printInOrder(N);
		return new String(sb);
	}

}