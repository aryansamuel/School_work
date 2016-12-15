//-----------------------------------------------------------------------------------------------
// Queue.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 05/11/16
// Programming Assignment 4
// Simple linked list that creates a list of Objects. Functions include adding, removing,
// and calling Objects. Can delete list and return length of list as well.
//-----------------------------------------------------------------------------------------------

public class Queue implements QueueInterface {
	
	// Private inner node class
	private class Node {
		Object item;
		Node next;
		
		Node (Object x) {
			item = x;
			next = null;
		}
	}
	
	private Node head;
	private int numItems;	
	
	// Queue()
	// Constructor for Queue class
	public Queue() {
		head = null;
		numItems = 0;
	}
	
	// ADT Operations--------------------------------------------------------------------
	
	// isEmpty()
    // pre: none
    // post: returns true if this Queue is empty, false otherwise
    public boolean isEmpty() {
		return (numItems == 0);
	}

    // length()
    // pre: none
    // post: returns the length of this Queue.
    public int length() {
		return numItems;
	}

    // enqueue()
    // adds newItem to back of this Queue
    // pre: none
    // post: !isEmpty()
    public void enqueue(Object newItem) {
		if (numItems == 0) {
			Node N = new Node(newItem);
			N.next = head;
			head = N;
		} else {
			Node N = head;
			while (N.next != null) N = N.next;
			Node C = N.next;
			N.next = new Node(newItem);
			N = N.next;
			N.next = C;
		}
		numItems++;
	}

    // dequeue()
    // deletes and returns item from front of this Queue
    // pre: !isEmpty()
    // post: this Queue will have one fewer element
    public Object dequeue() throws QueueEmptyException {
		if (numItems == 0) {
			throw new QueueEmptyException("Queue Error: calling dequeue() on empty Queue");
		}
		Node N = head;
		head = head.next;
		N.next = null;
		numItems--;
		return head;
	}

    // peek()
    // pre: !isEmpty()
    // post: returns item at front of Queue
    public Object peek() throws QueueEmptyException {
		if (numItems == 0) {
			throw new QueueEmptyException("Queue Error: calling peek() on empty Queue");
		}
		Node N = head;
		return N.item;
	}

    // dequeueAll()
    // sets this Queue to the empty state
    // pre: !isEmpty()
    // post: isEmpty()
    public void dequeueAll() throws QueueEmptyException {
		if (numItems == 0) {
			throw new QueueEmptyException("Queue Error: calling dequeueAll() on empty Queue");
		}
		head = null;
		numItems = 0;
	}

    // toString()
    // overrides Object's toString() method
    public String toString() {
		Node N = head;
		StringBuffer sb = new StringBuffer();
		for ( ; N != null; N=N.next) {
			sb.append(N.item).append(" ");
		}
		return new String(sb);
	}
}
		
		