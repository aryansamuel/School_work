// Sum.java

class sum {
   public static void main (String[] args) {
      System.out.println(sum(0,5));
   }

   static int sum (int n, int m) {
      if (n<=m) {
         return sum(n+1, m) + n;
      } return 0;
   }
}
