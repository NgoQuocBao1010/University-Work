package DataStructure;

public class UseLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arrs = {7, 9, 2};
		LinkedList l = new LinkedList();
		
		for (int num: arrs) {
			l.add(num);
		}
		
		//l.deleteNode(2);
		l.sort();
		
		//System.out.println(l.max());
		//System.out.println(l.min());
		
		System.out.println(l.toString());
	}

}
