//--------------------------------------------------------------------------------------------------------
// List.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/22/16
// Programming Assignment 3
// List ADT that is implemented by Matrix.java. Does basic operations such as inserting and deleting
// Matric, all while moving the "cursor".
//--------------------------------------------------------------------------------------------------------

class List {
	
	// Private inner node class
	private class Node {
		Object data;
		Node next;
		Node prev;
		
		// Constructor
		Node (Object x) {
			data = x;
			next = prev = null;
		}
		
		//toString()
		public String toString() {
			return String.valueOf(data);
		}
	}
	
	// Fields
	private Node front;
	private Node back;
	private Node cursor;
	private int length;
	private int index;
	
	// Constructor
	List() {
		front = back = null;
		length = 0;
		index = -1;
	}
	
	
	// Access Functions ---------------------------------------------------------------
	
	// length()
	// returns the number of elements in the List
	int length() {
		return length;
	}
	
	// index()
	// If cursor is defined, returns index of cursor element. Otherwise returns -1
	int index() {
		if (cursor != null) {
			return index;
		} else return -1;
	}
	
	// front()
	// Returns front element.
	// Pre: length()>0
	Object front() {
		if (length <= 0) {
			throw new RuntimeException("List Error: front() called on empty List");
		}
		return front.data;
	}
	
	// back()
	// Returns back element.
	// Pre: length()>0
	Object back() {
		if (length <= 0) {
			throw new RuntimeException("List Error: back() called on empty List");
		}
		return back.data;
	}
	
	// get()
	// Returns cursor element.
	// Pre: length()>0, index()>=0
	Object get() {
		if (length <= 0) {
			throw new RuntimeException("List Error: get() called on empty List");
		}
		if (index < 0) {
			throw new RuntimeException("List Error: get() called on null index");
		}
		return cursor.data;
	}
	

	// Manipulation Procedures -------------------------------------------------------------
	
	// clear()
	// Resets this List to its original empty state
	void clear() {
		front = back = null;
		length = 0;
		index = -1;
	}
	
	// moveFront()
	// If list is non-empty, places cursor under front element, otherwise does nothing.
	void moveFront() {
		if (length > 0) {
			cursor = front;
			index = 0;
		}
	}
	
	// moveBack()
	// If list is non-empty, places cursor under back element, otherwise does nothing.
	void moveBack() {
		if (length > 0) {
			cursor = back;
			index = length - 1;
		}
	}
	
	// movePrev()
	// If cursor is defined and not at front, moves cursor one step toward
	// front of this List, if cursor is defined and at front, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void movePrev() {
		if (cursor!=null && cursor!=front) {
			cursor = cursor.prev;
			index--;
		} else if (cursor!=null && cursor==front) {
			cursor = null;
			index = -1;
		}
	}
	
	// moveNext()
	// If cursor is defined and not at back, moves cursor one step toward
	// back of this List, if cursor is defined and at back, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void moveNext() {
		if (cursor!=null && cursor!=back) {
			cursor = cursor.next;
			index++;
		} else if (cursor!=null && cursor==back) {
			cursor = null;
			index = -1;
		}
	}
	
	// prepend()
	// Insert new element into this List. If List is non-empty,
	// insertion takes place before front element.
	void prepend(Object data) {
		Node N = new Node(data);
		
		if (length <= 0) {
			front = back = N;
		} else {
			front.prev = N;
			N.next = front;
			front = N;
		}
		
		length++;
	}
	
	// append()
	// Insert new element into this list. If List is non-empty,
	// inswertion takes place after back element.
	void append(Object data) {
		Node N = new Node(data);
		
		if (length <= 0) {
			front = back = N;
		} else {
			back.next = N;
			N.prev = back;
			back = N;
		}
		
		length++;		
	}
	
	// insertBefore()
	// Insert new element before cursor.
	// Pre: length()>0, index()>=0
	void insertBefore(Object data) {
		if (length <= 0) {
			throw new RuntimeException("List Error: insertBefore() called on empty List");
		}
		if (index < 0) {
			throw new RuntimeException("List Error: insertBefore() called on null index");
		}
		
		Node N = new Node(data);
		
		if (cursor.prev != null) {
			cursor.prev.next = N;
			N.prev = cursor.prev;
		} else front = N;
		
		cursor.prev = N;
		N.next = cursor;
		
		index++;
		length++;
	}
	
	// insertAfter()
	// Inserts new element after cursor.
	// Pre: length()>0, index()>=0
	void insertAfter(Object data) {
		if (length <= 0) {
			throw new RuntimeException("List Error: insertAfter() called on empty List");
		}
		if (index < 0) {
			throw new RuntimeException("List Error: insertAfter() called on null index");
		}
		
		Node N = new Node(data);
		
		if (cursor.next != null) {
			cursor.next.prev = N;
			N.next = cursor.next;
		} else back = N;
		
		cursor.next = N;
		N.prev = cursor;

		length++;
	}
	
	// deleteFront()
	// Deletes the front element.
	// Pre: length()>0
	void deleteFront() {
		if (length <= 0) {
			throw new RuntimeException("List Error: deleteFront() called on empty List");
		}
		
		if (cursor != null) {
			if (cursor == front) {
				cursor = null;
				index = -1;
			} else {
				cursor = cursor.prev;
				index--;
			}
		}
		
		front = front.next;
		front.prev = null;
		length--;
	}
	
	// deleteBack()
	// Deletes the back element.
	// Pre: length()>0
	void deleteBack() {
		if (length <= 0) {
			throw new RuntimeException("List Error: deleteBack() called on empty List");
		}
		
		if (cursor == back) {
			cursor = null;
			index = -1;
		}
		
		back = back.prev;
		back.next = null;
		length--;
	}
	
	// delete()
	// Deletes cursor element, making cursor undefined.
	// Pre: length()>0, index()>=0
	void delete() {
		if (length <= 0) {
			throw new RuntimeException("List Error: delete() called on empty List");
		}
		if (index < 0) {
			throw new RuntimeException("List Error: delete() called on null index");
		}
		
		cursor.prev.next = cursor.next;
		cursor.next.prev = cursor.prev;
		cursor = null;
		index = -1;
		length--;
	}
	
	
	// Other Functions ----------------------------------------------------------------
	
	// toString()
	// Overides Object's toString() method.
	public String toString(){
		StringBuffer sb = new StringBuffer();
		Node N = front;
		int i = 1;
		while(N!=null){
			sb.append(N.toString());
			sb.append(" ");
			i++;
			N = N.next;
		}
		return new String(sb);
	}
	
	// equals()
	// Returns true if this Object and L are the same integer
	// sequence. The cursor is ignored in both lists.
	public boolean equals(Object x) {
		boolean eq = false;
		List L = (List)x;
		Node N = L.front;
		Node M = this.front;
		
		while (N.next!=null && M.next!=null) {
			if (N.data == M.data) {
				eq = true;
			}
			else eq = false;
			N = N.next;
			M = M.next;
		}
		return eq;
	}

}
