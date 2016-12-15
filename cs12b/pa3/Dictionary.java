//---------------------------------------------------------------------------------------------------------------------
// Dictionary.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 04/24/16
// Programming Assignment 3
// A Dictionary ADT with pairs of Strings called Keys and Values. 
// Performs various functions such as creating and deleting a Dictionary, 
// and inserting, finding, or removing specific items to and fromt it.
//---------------------------------------------------------------------------------------------------------------------

public class Dictionary implements DictionaryInterface {
	
	// Private inner Node class
	private class Node {
		String key;
		String value;
		Node next;
		
		Node (String x, String y) {
			key = x;
			value = y;
			next = null;
		}
	}
	
	// Fields for Dictionary class
	private Node head;
	private int numItems;
	
	// Dictionary()
	// Construct for Dictinary class
	public Dictionary() {
		head = null;
		numItems = 0;
	}
	
	// Private helper function --------------------------------------------------------------
	
	// findKey()
	private Node findKey (String key) {
		Node N = head;
		while (N != null) {
			if (N.key.equals(key)) return N;
			else N = N.next;
		}
		return N;
	}
	
	// ADT Operations -----------------------------------------------------------------------
	
	// isEmpty()
	// pre: none
	// returns true if this Dictionary is empty, false otherwise
	public boolean isEmpty() {
		return (numItems == 0);
	}
		
	// size()
	// pre: none
	// returns the number of entries in this dictionary
	public int size() {
		return numItems;
	}

	// lookup()
	// pre: none
	// returns value associated key, or null reference if no such key exists
	public String lookup(String key) {
		Node N = findKey(key);
		if (N == null) return null;
		return N.value;
	}

	// insert()
	// pre: lookup(key) == null
	// inserts new (key, value) pair into this dictionary
	public void insert(String key, String value) throws DuplicateKeyException {
		if (findKey(key) != null) {
			throw new DuplicateKeyException("Dictionary Error: (" + key + ", " + value + ") already exists");
		}
		if (key.equals("1")) {
			Node N = new Node(key,value);
			N.next = head;
			head = N;
		} else {
			Node N = head;
			while (N.next != null) N = N.next;
			Node C = N.next;
			N.next = new Node(key,value);
			N = N.next;
			N.next = C;
		}	
		numItems++;
	}
	
	// delete()
	// pre: lookup(key) != null
	// delets pair with the given key
	public void delete(String key) throws KeyNotFoundException {
		if (findKey(key) == null) {
			throw new KeyNotFoundException("Dictionary Error: delete() called on nonexistent key:" + key);
		} 
		if (key.equals("1")) {
			Node N = head;
			head = head.next;
			N.next = null;
		} else {
			Node P = head;
			while (!P.next.key.equals(key)) P = P.next;
			Node N = P.next;
			P.next = N.next;
			N.next = null;
		}
		numItems--;
	}
	
	// makeEmpty()
	// pre: none
	public void makeEmpty() {
		head = null;
		numItems = 0;
	}
	
	// toString()
	// pre: none
	// returns a string representation of this dictionary
	// overrides Object's toString() method
	public String toString() {
		Node N = head;
		StringBuffer sb = new StringBuffer();
		for ( ; N != null; N=N.next) {
			sb.append(N.key).append(" ").append(N.value).append("\n");
		}
		return new String(sb);
	}
}
	
	
	
