// Problem4.java
class Node{
 int item;
 Node next;
 Node(int x){
 item = x;
 next = null;
 }
}
// In some class in the same package as Node:
static int product(Node H){
	if (H==null) {
		return 1
	} else {
		int x;
		x = H.item*product(H.next);
	}
	return x;
}