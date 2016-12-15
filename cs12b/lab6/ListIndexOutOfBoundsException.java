//-----------------------------------------------------------------------------
// ListIndexOutOfBoundsException.java
// Aryan Samuel
// arsamuel
// CMPS 12M
// 05/20/16
// Lab 6
// Exception class for List.java
//-----------------------------------------------------------------------------

@SuppressWarnings("serial")
public class ListIndexOutOfBoundsException extends IndexOutOfBoundsException{
   public ListIndexOutOfBoundsException(String s){
      super(s);
   }
}