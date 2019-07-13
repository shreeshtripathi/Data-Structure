package Lecture23;

public class FloydCycle {
	
	class Node{
		int data;
		Node next;
		
		Node(int data){
			this.data = data;
			this.next = null;
		}
	};
	
	public void display(Node node) {
		for(Node temp = node; temp != null; temp = temp.next) {
			System.out.print(temp.data  + " ");
		}
		System.out.println();
	}
	
	private void remLoop(Node slow, Node fast) {
		while()
	}
	
	public boolean detectAndRemLoop(Node node) {
		Node slow = node;
		Node fast = node;
		while(fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
			if(slow == fast) {
				remLoop(node, fast);
				return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		
	}

}
