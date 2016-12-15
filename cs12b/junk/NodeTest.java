// NodeTest.java
// file: NodeTest.java
public class NodeTest{
 public static void main(String[] args){
 Node H = new Node(9);
 H.next = new Node(7);
 H.next.next = new Node(5);
 // part (a) refers to this point in the code

 for(Node N=H; N!=null; N=N.next) System.out.print(N.item+" ");
 System.out.println();
 
 Node P = H.next.next;
 H.next.next = new Node(4);
 H.next.next.next = P;
 for(Node N=H; N!=null; N=N.next) System.out.print(N.item+" ");
 System.out.println();
 printForward(H);
 printBackward(H);
 }
 
 static void printForward(Node H) {
	 if (H!=null) {
		 System.out.print(H.item + " ");
		 printForward(H.next);
	 }
	 else System.out.println();
 }
 
 static void printBackward(Node H) {
	 if (H.next != null) {
		 printBackward(H.next);
	 }
	 System.out.print(H.item + " ");
 }
 
}
