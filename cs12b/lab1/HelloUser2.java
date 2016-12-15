//-----------------------------------------------------------------------------------------
// HelloUser2.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 03/31/16
// Lab 1
// Greets the user with a message that print the user's name, the day, and the time.
//-----------------------------------------------------------------------------------------

class HelloUser2 {
   public static void main (String[] args) {
      
      String username = System.getProperty("user.name");
      long time = System.currentTimeMillis();
      
      System.out.println("Hello " +username+ "!");
      System.out.printf("Today is %tA and the time is %tI:%tM%tp.%n", time, time, time, time);
   }
}
