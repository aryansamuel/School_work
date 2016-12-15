// Problem 5
public class problem5 {
	static String integerToString (int n, int b) {
		String s = "";
		if (n>0) {
			if (n/b > 0) s = integerToString (n/b, b);
			return s + String.valueOf(n%b);
		}
		else return s;
	}
 public static void main (String[] args) {
	System.out.println( integerToString(100,8));
 }
}
