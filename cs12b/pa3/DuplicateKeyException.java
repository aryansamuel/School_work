//--------------------------------------------------------------------
// DuplicateKeyException.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 04/24/16
// Programming Assignment 3
// Exception class that is thrown in Dictionary.java
//--------------------------------------------------------------------

public class DuplicateKeyException extends RuntimeException {
   public DuplicateKeyException(String s) {
      super(s);
   }
}
