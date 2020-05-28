package DataStructure;

public class Node {
	
	public int Data;
	public Node next;
	
	public Node(int data) {
		this.Data = data;
		this.next = null;
	}
	
	public Node (int data, Node n) {
		this.Data = data;
		this.next = n;
	}
}
