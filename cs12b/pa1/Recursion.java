//------------------------------------------------------------------------------------------------------------------
// Recursion.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 04/05/16
// Programming Assignment 1
// Prints an array, finds the minimum and maximum index, and then reverses it using three different methods.
//------------------------------------------------------------------------------------------------------------------

class Recursion {
	
   // reverseArray1()
   // Places the leftmost n elements of X[] into the rightmost n positions in
   // Y[] in reverse order
   static void reverseArray1(int[] X, int n, int[] Y) {
	   if (n>0) {
		   Y[n-1] = X[X.length-n];
		   reverseArray1(X, n-1, Y);
	   }
   }

   // reverseArray2()
   // Places the rightmost n elements of X[] into the leftmost n positions in
   // Y[] in reverse order.
   static void reverseArray2(int[] X, int n, int[] Y) {
	   if (n>0) {
		   Y[X.length-n] = X[n-1];
		   reverseArray2(X, n-1, Y);
	   }
   }
   
   // reverseArray3()
   // Reverses the subarray X[i...j].
   static void reverseArray3(int[] X, int i, int j){
	   int temp = X[j];
	   X[j] = X[i];
	   X[i] = temp;
	   if (j>X.length/2) reverseArray3(X, i+1, j-1);
   }
   
   // maxArrayIndex()
   // returns the index of the largest value in int array X
   static int maxArrayIndex(int[] X, int p, int r){
	   int ma1,ma2,q;
	   if (p>=r) return p;
	   else {
		   q = (p+r)/2;
		   ma1 = maxArrayIndex(X, p, q);
		   ma2 = maxArrayIndex(X, q+1, r);
		   if (X[ma1] > X[ma2]) return ma1;
		   else return ma2;
	   }
   }
   
   // minArrayIndex()
   // returns the index of the smallest value in int array X
   static int minArrayIndex(int[] X, int p, int r){
	   int mi1,mi2,q;
	   if (p>=r) return p;
	   else {
		   q = (p+r)/2;
		   mi1 = minArrayIndex(X, p, q);
		   mi2 = minArrayIndex(X, q+1, r);
		   if (X[mi1] < X[mi2]) return mi1;
		   else return mi2;
	   }
   }
   
   // main()
   public static void main(String[] args){
      
      int[] A = {-1, 2, 6, 12, 9, 2, -5, -2, 8, 5, 7};
      int[] B = new int[A.length];
      int[] C = new int[A.length];
      int minIndex = minArrayIndex(A, 0, A.length-1);
      int maxIndex = maxArrayIndex(A, 0, A.length-1);
      
      for(int x: A) System.out.print(x+" ");
      System.out.println(); 
      
      System.out.println( "minIndex = " + minIndex );  
      System.out.println( "maxIndex = " + maxIndex );  

      reverseArray1(A, A.length, B);
      for(int x: B) System.out.print(x+" ");
      System.out.println();
      
      reverseArray2(A, A.length, C);
      for(int x: C) System.out.print(x+" ");
      System.out.println();
      
      reverseArray3(A, 0, A.length-1);
      for(int x: A) System.out.print(x+" ");
      System.out.println();  
      
   }
   
}
