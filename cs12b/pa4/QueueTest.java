//-----------------------------------------------------------------------------------------------
// QueueTest.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 05/11/16
// Programming Assignment 4
// Test client for the Queue ADT.
//-----------------------------------------------------------------------------------------------

public class QueueTest {
	public static void main (String[] args) {
		
		Job a = new Job(0, 1);
		Job b = new Job(2, 3);
		Job c = new Job(4, 5);
		Job d = new Job(6, 7);
		Job e = new Job(8, 9);
		
		Queue A = new Queue();
		
		// Test 1
		A.enqueue(a);
		System.out.println(A);
		// Test 2
		A.enqueue(b);
		A.enqueue(c);
		A.enqueue(d);
		A.enqueue(e);
		System.out.println(A);
		
		// Test 3
		System.out.println(A.isEmpty());
		System.out.println(A.length());
		System.out.println();
		
		// Test 4
		System.out.println(A.peek());
		System.out.println();
		
		// Test 5
		A.dequeue();
		System.out.println(A);
		A.dequeue();
		System.out.println(A.peek());
		System.out.println();
		
		// Test 6
		A.dequeueAll();
		System.out.println(A.isEmpty());
		
		// Test 7 / QueueEmptyException Test
		//A.peek();
		//A.dequeue();
		//A.dequeueAll();
		
	}
}