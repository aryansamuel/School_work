//--------------------------------------------------------------------------------------------------------
// ListTest.java
// Aryan Samuel
// arsamuel
// CMPS 101
// 10/22/16
// Programming Assignment 3
// Test client for the List ADT.
//--------------------------------------------------------------------------------------------------------

public class ListTest {
	public static void main (String[] args) {
		List A = new List();
		List B = new List();
		
		String[] s = {"Hello","my","name","is","Aryan","Samuel","and","I","am","known","to","be","the","best","in","the","whole","wide","world","!"};
      
		for(int i=0; i<20; i++) {
			A.append(s[i]);
			B.prepend(s[i]);
		}
		System.out.println(A);
		//System.out.println(B);
      
		for(A.moveFront(); A.index()>=0; A.moveNext()){
			System.out.print(A.get()+" ");
		}
		System.out.println();
		for(B.moveBack(); B.index()>=0; B.movePrev()){
			System.out.print(B.get()+" ");
		}
		System.out.println();

		System.out.println(A.equals(B));
		System.out.println(A.equals(A));
      
		A.moveFront();
		for(int i=0; i<5; i++) A.moveNext(); // at index 5
		A.insertBefore("AWESOME");                  // at index 6
		for(int i=0; i<9; i++) A.moveNext(); // at index 15
		A.insertAfter(", yes,");
		for(int i=0; i<5; i++) A.movePrev(); // at index 10
		System.out.println(A);
		System.out.println(A.length());
		A.delete();
		A.deleteFront();
		A.deleteBack();
		System.out.println(A);
		System.out.println(A.length());
		A.clear();
		System.out.println(A.length());
	}
}