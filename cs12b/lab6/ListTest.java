//--------------------------------------------------------------------------------------------------------
// ListTest.java
// Aryan Samuel
// arsamuel
// CMPS 12M
// 05/20/16
// Lab 6
// A test client for the List ADT. Each new Test block shows what was added only
// after the previous test block passed i.e. no erros when compiled, expected output.
//--------------------------------------------------------------------------------------------------------

public class ListTest {
	public static void main (String[] args) {
		
		List<String> A = new List<String>();
		
		// Test 1
		A.add(1, "one");
		System.out.println(A);
		// Test 2
		A.add(2, "two");
		A.add(3, "three");
		A.add(4, "four");
		System.out.println(A);
		
		// Test 3
		System.out.println(A.isEmpty());
		System.out.println(A.size());
		System.out.println();
		
		// Test 4
		System.out.println(A.get(2));
		System.out.println();
		
		// Test 5
		A.remove(3);
		System.out.println(A);
		A.remove(1);
		System.out.println(A);
		System.out.println();
		
		// Test 6
		A.removeAll();
		System.out.println(A.isEmpty());
		
		// Test 7
		List<Double> B = new List<Double>();
		B.add(1, 1.2);
		B.add(2, 5.5);
		B.add(3, 7.3);
		System.out.println(B);
		
		// Test 8 / IndexOutOfBoundsException Test
		//B.add(5, 4.4);
		//B.remove(6);
		//B.get(7);
		
		// Test 9
		List<Double> C = new List<Double>();
		C.add(1, 1.2);
		C.add(2, 5.5);
		C.add(3, 7.3);
		System.out.println(C);
		
		// Test 10
		System.out.println(B.equals(C));
		System.out.println(A.equals(B));
	}
}