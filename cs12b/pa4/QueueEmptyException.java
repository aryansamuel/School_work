//-----------------------------------------------------------------------------------------------
// QueueEmptyException.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 05/11/16
// Programming Assignment 4
// Exception class that is thrown in Queue.java
//-----------------------------------------------------------------------------------------------

public class QueueEmptyException extends RuntimeException {
   public QueueEmptyException(String s) {
      super(s);
   }
}
