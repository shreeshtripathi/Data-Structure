package Lecture23;

public class LinkedList {

	private class Node {
		public int data;
		public Node next;
	}

	private Node head;

	private Node tail;

	private int size;
	
	private Node rdrLeft;

	private void handleAddwhen0(int data) {
		Node nn = new Node();
		nn.data = data;
		head = tail = nn;
		size = 1;
	}

	private int handleRemWhenSize1() {
		int temp = head.data;
		head = tail = null;
		size = 0;
		return temp;
	}

	private Node getNodeAt(int indx) {
		Node temp = head;
		for (int i = 0; i < indx; i++) {
			temp = temp.next;
		}

		return temp;
	}

	public void display() {
		Node temp = head;
		for (int i = 0; i < size; i++) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public int getSize() {
		return size;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void addFirst(int data) {
		if (size == 0) {
			handleAddwhen0(data);
		} else {
			// Space
			Node nn = new Node();
			// Data and next
			nn.data = data;
			nn.next = head;
			// connect
			nn.next = head;
			// Summary
			head = nn;
			size++;
		}
	}

	public void addLast(int data) {
		if (size == 0) {
			handleAddwhen0(data);
		} else {
			// Space
			Node nn = new Node();
			// Data and next
			nn.data = data;
			tail.next = nn;
			// connect
			nn.next = null;
			// Summary
			tail = nn;
			size++;
		}
	}

	public void addAt(int data, int indx) {
		if (indx < 0 || indx >= size) {
			return;
		} else if (indx == 0) {
			addFirst(data);
		} else if (indx == size) {
			addLast(data);
		} else {
			Node nm1 = getNodeAt(indx - 1);
			Node np1 = nm1.next;
			Node n = new Node();
			n.data = data;
			nm1.next = n;
			n.next = np1;
			size++;
		}
	}

	public int getFirst() {
		if (size == 0) {
			return -1;
		} else {
			return head.data;
		}
	}

	public int getLast() {
		if (size == 0) {
			return -1;
		} else {
			return tail.data;
		}
	}

	public int getAt(int indx) {
		if (indx < 0 || indx >= size) {
			return -1;
		} else {
			Node temp = getNodeAt(indx);
			return temp.data;
		}

	}

	public int removeFirst() {
		if (size == 0) {
			return -1;
		} else if (size == 1) {
			return handleRemWhenSize1();
		} else {
			Node oh = head;
			head = oh.next;
			size--;
			int temp = oh.data;
			return temp;
		}
	}

	public int removeLast() {
		if (size == 0) {
			return -1;
		} else if (size == 1) {
			return handleRemWhenSize1();
		} else {
			Node s1 = getNodeAt(size - 2);
			s1.next = null;
			int temp = tail.data;
			tail = s1;
			size--;
			return temp;
		}
	}

	public int removeAT(int indx) {
		if (indx < 0 || indx >= size) {
			return -1;
		} else if (indx == 0) {
			return removeFirst();
		} else if (indx == size - 1) {
			return removeLast();
		} else {
			Node nm1 = getNodeAt(indx - 1);
			Node n = nm1.next;
			Node np1 = n.next;
			int temp = n.data;
			nm1.next = np1;
			size--;
			return temp;
		}
	}

	
	public void rdi() {
		int li = 0;
        int ri = size - 1;
        while(li <= ri){
            Node left = getNodeAt(li);
            Node right = getNodeAt(ri);
            int temp = left.data;
            left.data = right.data;
            right.data = temp;
            li++;
            ri--;
        }
	}
	
	public void rpi() {
        Node prev = null;
        Node cur = head;
        Node next = cur.next;
        while(cur != null){
            cur.next = prev;
            prev = cur;
            cur = next;
            if(next != null){
                next = next.next;
            }
        }
        Node temp = head;
        head = tail;
        tail = temp;
	}
	
	private void displayReverse(Node node) {
		if(node == null){
            return;
        }
        displayReverse(node.next);
        System.out.print(node.data + "->");
	}
	
	public void displayReverse(){
        displayReverse(head);
        System.out.println();
    }
	
	private void rpr(Node node) {
		if(node == tail) {
			return;
		}
		rpr(node.next);
		node.next.next = node;
	}
	
	public void rpr() {
		rpr(head);
		Node temp = head;
		head = tail;
		tail = temp;
		tail.next = null;
	}
	
	private void rdr(Node right, int floor) {
		if(right == null) {
			return;
		}
		rdr(right.next, floor + 1);
		if(floor >= size / 2) {
			int temp = rdrLeft.data;
			rdrLeft.data = right.data;
			right.data = temp;
			
			rdrLeft = rdrLeft.next;
			
		}
	}
	
	public void rdr() {
		rdrLeft = head;
		rdr(head, 0);
	}
	
	private boolean isPalindrome(Node right) {
		if(right == null){
            return true;
        }
        boolean rres = isPalindrome(right.next);
        
        boolean mres = rres == true && rdrLeft.data == right.data;
        
        rdrLeft = rdrLeft.next;
        return mres;
	}
	
	public boolean isPalindrome(){
        rdrLeft = head;
        Node right = head;
        return isPalindrome(right);
    }
	
	private void fold(Node right, int floor) {
		if(right == null) {
			return;
		}
		fold(right.next, floor + 1);
		if(floor > size / 2) {
			right.next = rdrLeft.next;
			rdrLeft.next = right;
			rdrLeft = right.next;
		} else if(floor == size/2) {
			tail = right;
			right.next = null;
		}
	}
	
	public void fold() {
		rdrLeft = head;
		Node right = head;
		fold(right, 0);
	}
	
	private void unfold(Node temp1) {
		if(temp1.next == null) {
			head = tail = temp1;
			return;
		} else if(temp1.next.next == null) {
			head = temp1;
			tail = temp1.next;
			return;
		}	
		
		Node temp2 = temp1.next;
		unfold(temp1.next.next);
		temp1.next = head;
		head = temp1;
		tail.next = temp2;
		tail = temp2;
		tail.next = null;
	}
	
	public void unfold() {
		Node temp1 = head;
		unfold(temp1);
	}
	
	public void removeDuplicates(){
        LinkedList nl = new LinkedList();
        //Use this pointer
        while(this.size > 0){
            int temp = removeFirst();
            if(nl.size == 0 || nl.tail.data != temp){
                nl.addLast(temp);
            }
        }
        // change in original head and tail
        this.head = nl.head;
        this.tail = nl.tail;
        this.size = nl.size;

        // no need to worry about destructor, garbage collector perform smartly in JAVA
    }
	
	public void OddEven(){
        LinkedList l1 = new LinkedList();
        LinkedList l2 = new LinkedList();
        // l1 is for Odd and l2 is for Even
        while(this.size > 0){
            int temp = this.removeFirst();
            if(temp % 2 == 0){
                l2.addLast(temp);
            } else {
                l1.addLast(temp);
            }
        }
        if(l1.size == 0){
            this.head = l2.head;
            this.tail = l2.tail;
            this.size = l2.size;
        } else if(l2.size == 0){
            this.head = l1.head;
            this.tail = l1.tail;
            this.size = l1.size;
        } else {
            l1.tail.next = l2.head;
            this.head = l1.head;
            this.tail = l2.tail;
            this.size = l1.size + l2.size;
        }
    }
	
	public void kReverse(int n){
        LinkedList accu = new LinkedList(); // accumulator
        while(this.size > 0){
            LinkedList temp = new LinkedList();
            for(int i = 0; i< n && this.size > 0; i++){
                    int data = this.removeFirst();
                    temp.addFirst(data);
            }
            if(accu.size == 0){
                accu.head = temp.head;
                accu.tail = temp.tail;
                accu.size = temp.size;
//            	accu = temp;
            } else {
                accu.tail.next = temp.head;
                accu.tail = temp.tail;
                accu.size = accu.size + temp.size;
            }
        }
        this.head = accu.head;
        this.tail = accu.tail;
        this.size = accu.size;
    }
	
	private Node midNode(Node first, Node last){
        Node slow = first;
        Node fast = first;
        while(fast.next != last && fast != last){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
	
	public int midElement(){
        Node mid = midNode(this.head, this.tail);
        return mid.data;
    }
    
    public int kLast(int k){
        Node slow = head;
        Node fast = head;
        while(k != 0){
            fast = fast.next;
            k--;
        }
        while(fast != null){
            slow = slow.next;
            fast = fast.next;
        }
        return slow.data;
    }
	
    public void mergeTwoSortedList(LinkedList l1, LinkedList l2){
        Node temp1 = l1.head;
        Node temp2 = l2.head;
        while(temp1 != null && temp2 != null){
            if(temp1.data < temp2.data){
                this.addLast(temp1.data);
                temp1 = temp1.next;
            } else{
                this.addLast(temp2.data);
                temp2 = temp2.next;
            }
        }
        if(temp1 == null){
            while(temp2 != null){
                this.addLast(temp2.data);
                temp2 = temp2.next;
            }
        }
        if(temp2 == null){
            while(temp1 != null){
                this.addLast(temp1.data);
                temp1 = temp1.next;
            }
        }
    }
    
    private LinkedList mergeSort(Node first, Node last){
        if(first == last){
            LinkedList l4 = new LinkedList();
            l4.addLast(first.data);
            return l4;
        }
        Node temp = midNode(first, last);
        LinkedList ls1 = new LinkedList();
        ls1 = mergeSort(first, temp);
        
        LinkedList ls2 = new LinkedList();
        ls2 = mergeSort(temp.next, last);
        
        LinkedList list = new LinkedList();
        list.mergeTwoSortedList(ls1, ls2);
        
        return list;

    }
    
    public LinkedList  mergeSort(){
        LinkedList res = mergeSort(this.head, this.tail);
        return res;
    }
	
    private int Addition(Node oh, Node th,int s1, int s2) {
    	if(s1 == 0 && s2 == 0) {
    		return 0;
    	}
    	
    	int c;
    	int t1;
    	int t2;
    	if(s1 > s2) {
    		t1 = oh.data;
    		t2 = 0;
    		c = Addition(oh.next, th, s1 - 1, s2);
    	} else if(s2 > s1) {
    		t2 = th.data;
    		t1 = 0;
    		c = Addition(oh, th.next, s1, s2 - 1);
    	} else {
    		t1 = oh.data;
    		t2 = th.data;
    		c = Addition(oh.next, th.next, s1 - 1, s2 - 1);
    	}
    	int t3 = t1 + t2 + c;
    	this.addFirst(t3 % 10);
    	c = t3 / 10;
    	
    	return c;
    	
    }
    
    public void Addition(LinkedList l1, LinkedList l2) {
    	int car = Addition(l1.head, l2.head, l1.size, l2.size);
    	if(car != 0) {
    		this.addFirst(car);
    	}
    }
    
//    private int multiplication() {
//    	
//    }
    
    
    public void multiplication(LinkedList l1, LinkedList l2) {
    	
    }
    
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.addLast(10);
		list.addLast(20);
		list.addLast(30);
		list.addLast(40);
		list.addLast(50);
		list.addLast(60);
		list.addLast(70);
//		System.out.println(list.midElement());
//		System.out.println(list.kLast(2));
		
		LinkedList l1 = new LinkedList();
	    l1.addLast(9);
	    l1.addLast(8);
	    l1.addLast(7);
	    l1.addLast(6);
	    l1.addLast(5);
	    l1.addLast(4);
	    l1.addLast(3);
	    l1.addLast(2);
	    l1.addLast(1);

	    // LinkedList l3;
	    // l3.mergeTwoSortedList(l1, l2);
	    // l3.display();
	    LinkedList ll3 = new LinkedList();
	    ll3 = l1.mergeSort();
//	    ll3.display();
//	    l1.display();
	    
	    
	    LinkedList s1 = new LinkedList();
	    LinkedList s2 = new LinkedList();
	    s1.addLast(9);
	    s1.addLast(9);
	    s1.addLast(9);
//	    s1.addLast(6);
//	    s1.addLast(2);
	    s2.addLast(1);
//	    s2.addLast(7);
//	    s2.addLast(3);
	    LinkedList s3 = new LinkedList();
	    s3.Addition(s1, s2);
	    s3.display();
	}

}