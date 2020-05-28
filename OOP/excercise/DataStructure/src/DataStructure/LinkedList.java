package DataStructure;

public class LinkedList {
	public Node head;
	public Node tail;
	private int countMember;
	private int maximum = -1000000;
	private int minimum = 1000000;
	
	// initiate linked list
	public LinkedList() {
		this.head = this.tail = null;
	}
	
	// check whether list is empty
	public boolean isEmpty() {
		return (this.head == null);
	}
	
	//add a node into the list
	public void add(int data) {
		Node p = new Node(data);
		
		if (this.isEmpty()) {
			this.head = this.tail = p;
			return;
		}
		
		this.tail.next = p;
		this.tail = p;
		this.countMember ++;
		
		if (p.Data > this.maximum) this.maximum = p.Data;
		
		if (p.Data < this.minimum) this.minimum = p.Data;
	}
	
	// find whether a node is in a list
	public boolean inList(int data) {
		if (this.isEmpty()) return false;
		
		for (Node i = this.head; i != null; i = i.next) {
			if (i.Data == data) {
				return true;
			}
		}
		
		return false;
	}
	
	//delete first node in a list
	private void deleteFirstNode() {
		Node p = this.head;
		this.head = p.next;
		p = null;
	}
	
	//delete last node of a list
	private void deleteLastNode() {
		Node i = this.head;
		Node p = this.tail;
		
		while (i.next != this.tail) {
			i = i.next;
		}
		
		this.tail = i;
		this.tail.next = null;
		
		p = null;
	}
	
	//delete any node in a list
	public void deleteNode(int data) {
		if (!this.inList(data)) return;
		
		if (this.head.Data == data) {
			this.deleteFirstNode();
			return;
		}
		
		if (this.tail.Data == data) {
			this.deleteLastNode();
			return;
		}
		
		for (Node i = this.head; i != this.tail; i = i.next) {
			if (i.next.Data == data) {
				Node p = i.next;
				i.next = p.next;
				p = null;
				return;
			}
		}
	}
	
	//sorting the list from small to big
	public void sort() {
		for (Node i = this.head; i != this.tail ; i = i.next) {
			for (Node j = i.next; j != null; j = j.next) {
				if (i.Data > j.Data) {
					int temp = i.Data;
					i.Data = j.Data;
					j.Data = temp;
				}
			}
		}
	}
	
	//find the max value in the list
	public int max() {
		return this.maximum;
	}
	
	//find the min value in the list
	public int min() {
		return this.minimum;
	}
	
	//convert to String
	public String toString() {
		if (this.isEmpty()) return "[]";
		
		String result = "[";
		
		for (Node i = this.head; i != null; i = i.next) {
			result += i.Data;
			
			if (i.next == null) {
				break;
			}
			result += ", ";
		}
		result += "]";
		return result;
	}
}