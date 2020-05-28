package DataStructure;

public class Stack {
	// First in Last out
	private Node top;
	
	public Stack() {
		top = null;
	}
	
	// check whether stack is empty or not
	public boolean isEmpty() {
		return (top == null);
	}
	
	//take a look at the element at the top of the stack
	public int atTop() {
		return top.Data;
	}
	
	//add element in the top
	public void push(int data) {
		Node p = new Node(data);
		
		if (this.isEmpty()) {
			top = p;
			return;
		}
		
		p.next = top;
		top = p;
	}
	
	//take out and return the top element
	public int Pop() {
		if (this.isEmpty()) return 0;
		
		Node p = top;
		top = p.next;
		
		return p.Data;
	}
	
	public String toString() {
		if (this.isEmpty()) return "[]";
		
		String result = "[";
		for (Node i = top; i != null; i = i.next) {
			result += i.Data;
			
			if (i.next == null) {
				result += "]";
				break;
			}
			result += ", ";
		}
		
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arrs = {1, 3, 4, 9, 11};
		Stack a = new Stack();
		
		for (int num: arrs) {
			a.push(num);
		}
		
		System.out.println(a.atTop());
		System.out.println(a.toString());
	}

}
