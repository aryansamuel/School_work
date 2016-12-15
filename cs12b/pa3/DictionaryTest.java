//------------------------------------------------------------------------------------------------
// DictionaryTest.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 04/24/16
// Programming Assignment 3
// A test client for the Dctionary ADT. Each new Test block shows what was added only
// after the previous test block passed i.e. no erros when compiled, expected output.
//------------------------------------------------------------------------------------------------

public class DictionaryTest {
	public static void main(String[] args) {
		Dictionary A = new Dictionary();
		System.out.println(A.isEmpty());
		// Test 1
		A.insert("1","a");
		// Test 2
		A.insert("2","b");
		A.insert("3","c");
		A.insert("4","d");
		A.insert("5","e");
		
		System.out.println(A);
		// Test 3
		System.out.println(A.size());
		System.out.println(A.isEmpty());
		System.out.println();
		
		// Test 4 / DuplicateKeyException Test
		//A.insert("1","a");
		
		// Test 5
		System.out.println(A.lookup("1"));
		System.out.println(A.lookup("4"));
		System.out.println();
		
		// Test 6
		A.delete("3");
		System.out.println(A);
		System.out.println(A.size());
		System.out.println();
		
		// Test 7 / KeyNotFoundException Test
		//A.delete("6");
		
		// Test 8
		A.makeEmpty();
		System.out.println(A.size());
		System.out.println(A);
	}
}