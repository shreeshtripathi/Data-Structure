package Lecture27;

import java.util.*;

public class GenericTree4 {
	public static class Node {
		int data;
		ArrayList<Node> children = new ArrayList<>();

		Node(int data) {
			this.data = data;
			this.children = new ArrayList<>();
		}
	}

	private static Node build(ArrayList<Integer> dlist) {
		Node root = null;
		ArrayList<Node> nlist = new ArrayList<>();
		for (int i = 0; i < dlist.size(); i++) {
			if (dlist.get(i) == -1) {
				nlist.remove(nlist.size() - 1);
			} else {
				Node nn = new Node(dlist.get(i));
				if (nlist.size() == 0) {
					root = nn;
				} else {
					Node lastN = nlist.get(nlist.size() - 1);
					lastN.children.add(nn);
				}
				nlist.add(nn);
			}
		}
		return root;
	}

	private static void display(Node root) {
		String s = root.data + "->";
		for (int i = 0; i < root.children.size(); i++) {
			s += root.children.get(i).data + ",";
		}
		System.out.println(s + ".");
		for (int i = 0; i < root.children.size(); i++) {
			display(root.children.get(i));
		}
	}

	private static int size(Node root) {
		int count = 1;
		for (int i = 0; i < root.children.size(); i++) {
			count += size(root.children.get(i));
		}
		return count;
	}

	private static int max(Node root) {
		int max = root.data;
		for (int i = 0; i < root.children.size(); i++) {
			int temp = max(root.children.get(i));
			if (temp > max) {
				max = temp;
			}
		}
		return max;
	}

	private static boolean find(Node root, int data) {
		if (root.data == data) {
			return true;
		}
		boolean isHere = false;
		for (int i = 0; i < root.children.size(); i++) {
			isHere = find(root.children.get(i), data);
			if (isHere) {
				return true;
			}
		}
		return false;
	}

	private static int height(Node root) {
		int maxH = 0;
		for (int i = 0; i < root.children.size(); i++) {
			int temp = height(root.children.get(i));
			if (temp > maxH) {
				maxH = temp;
			}
		}
		return maxH + 1;
	}

	private static ArrayList<Integer> nodeToRootPath(Node root, int dtf) {
		if (root.data == dtf) {
			ArrayList<Integer> bres = new ArrayList<>();
			bres.add(root.data);
			return bres;
		}
		for (int i = 0; i < root.children.size(); i++) {
			ArrayList<Integer> mres = nodeToRootPath(root.children.get(i), dtf);
			if (mres != null) {
				mres.add(root.data);
				return mres;
			}
		}
		return null;
	}
	
	private static int lca(Node root, int d1, int d2) {
		//LCA = lowest common ancestor
		ArrayList<Integer> path1 = nodeToRootPath(root, d1);
		ArrayList<Integer> path2 = nodeToRootPath(root, d2);
		int s1 = path1.size()-1;
		int s2 = path2.size()-1;
		int prev = - 1;
	    while(s1 >=0 && s2 >=0 && path1.get(s1) == path2.get(s2)){
	        prev = path1.get(s1);
	        s1--;
	        s2--;
	    }
	    return prev;
	}
	
	private static int distance(Node root, int d1, int d2) {
		ArrayList<Integer> path1 = nodeToRootPath(root, d1);
		ArrayList<Integer> path2 = nodeToRootPath(root, d2);
		if(path1 == null || path2 == null) {
			System.out.println("invalid data ");
			return -1;
		}
		int s1 = path1.size()-1;
		int s2 = path2.size()-1;
	    while(s1 >=0 && s2 >=0 && path1.get(s1) == path2.get(s2)){
	        s1--;
	        s2--;
	    }
	    return (s1 + 1) + (s2 + 1) + 1;
	}
	
	private static void mirror(Node root) {
		for(int i = 0; i < root.children.size(); i++) {
			mirror(root.children.get(i));
		}
		
		int left = 0;
		int right = root.children.size() - 1;
		while(left < right) {
			Node ln = root.children.get(left);
			Node rn = root.children.get(right);
			
			root.children.set(left, rn);
			root.children.set(right, ln);
			
			
			left++;
			right--;
		}
	}
	
	/* 28th March 2019 */
	
	private static Node linearize(Node root) {
		if(root.children.size() == 0) {
			return root;
		}
		Node ol = root.children.get(root.children.size() - 1);
	    Node olkitail = linearize(ol);

	    while(root.children.size() != 1){
	        Node sl = root.children.get(root.children.size() - 2);;
	        Node slkitail = linearize(sl);

	        Node oh = root.children.get(root.children.size() - 1);
	        root.children.remove(root.children.size() - 1);

	        slkitail.children.add(oh);
	    }
	    return olkitail;
	}
	
	private static boolean areSimilarStr(Node root1, Node root2) {
		if(root1.children.size() != root2.children.size()){
	        return false;
	    }
	    for(int i = 0; i < root1.children.size(); i++){
	        Node temp1 = root1.children.get(i);
	        Node temp2 = root2.children.get(i);
	        boolean rres = areSimilarStr(temp1, temp2);
	        if(rres == false){
	            return false;
	        }
	    }
	    return true;
	}
	
	private static boolean areMirrorStr(Node root1, Node root2) {
		if(root1.children.size() != root2.children.size()){
	        return false;
	    }

	    for(int i = 0; i < root1.children.size(); i++){
	        Node temp1 = root1.children.get(i);
	        Node temp2 = root2.children.get(root1.children.size() - i - 1);
	        if(areMirrorStr(temp1, temp2) == false){
	            return false;
	        }
	    }
	    return true;
	}
	
	private static boolean isSymmetrical(Node root) {
		return areMirrorStr(root, root);
	}
	
	/* 30th march 2019 */
	
	private static class heapMover{
		int mn = Integer.MAX_VALUE;
		int mx = Integer.MIN_VALUE;
		int sz = 0;
		int ht = 0;
		int cl = Integer.MAX_VALUE;
		int fr = Integer.MIN_VALUE;
		int preSuc = -1;
		int preDe = -1;
		
	}
	
	public static void multiSolver(Node root, heapMover h, int depth, int k){
	    h.sz++;
	    h.ht = depth > h.ht? depth: h.ht;
	    h.mn = root.data < h.mn? root.data: h.mn;
	    h.mx = root.data > h.mx? root.data: h.mx;
	    h.cl = root.data > k && root.data < h.cl? root.data : h.cl;
	    h.fr = root.data < k && root.data > h.fr? root.data : h.fr;

	    for(int i = 0; i < root.children.size(); i++){
	        multiSolver(root.children.get(i), h, depth + 1, k);
	    }

	}
	
	static int status = 0;
	
	public static void preSucDe(Node root, heapMover h, int k) {
		if(status == 0) {
			if(root.data != k) {
				h.preDe = root.data;
			}else {
				status = 1;
			}
		} else if(status == 1) {
			h.preSuc = root.data;
			status++;
		}
		
		for(int i = 0; i < root.children.size(); i++) {
			preSucDe(root.children.get(i), h, k);
		}
		
	}
	
	
	
	/*Date: 31st March 2019 */	
	
	public static class helper{
		int pd = -1;
		int sc = -1;
		int curr = -1;
		int prev = -1;
	}
	
	public static void preSucc2(helper mv, Node root, int key) {
		
		mv.prev = mv.curr;
		mv.curr = root.data;
		
		if(mv.curr == key) {
			mv.pd = mv.prev;
		} else if(mv.prev == key) {
			mv.sc = mv.curr;
		}
		
		for(int i = 0; i < root.children.size(); i++) {
			preSucc2(mv, root.children.get(i), key);
		}
	}
	
	
	public static class forLarge{
		int fr = Integer.MIN_VALUE;
	};
	
	public static void floorforKthLargest(Node root, forLarge h, int key){
	   
		h.fr = root.data < key && root.data > h.fr? root.data : h.fr;
		
	    for(int i = 0; i < root.children.size(); i++){
	        floorforKthLargest(root.children.get(i), h, key);
	    }

	}
	
	public static int kthLargest(Node root, int k) {
		forLarge h2 = new forLarge();
		int key = Integer.MAX_VALUE;
		for(int i = 0; i < root.children.size(); i++) {
			floorforKthLargest(root, h2, key);
			key = h2.fr;
			h2.fr = Integer.MIN_VALUE;
		}
		
		return key;
	}
	
	public static void levelOrder(Node root){
		LinkedList<Node> queue = new LinkedList<>();
		queue.addLast(root);
		while(queue.size() != 0) {
			Node fr = queue.getFirst();
			queue.removeFirst();
			System.out.print(fr.data + " ");
			for(int i = 0; i < fr.children.size(); i++) {
				queue.addLast(fr.children.get(i));
			}
		}
	}
	public static void levelOrderLineWise(Node root) {
		 LinkedList<Node> curr = new LinkedList<>();
		 LinkedList<Node> next = new LinkedList<>();
		 curr.addLast(root);
		 while(curr.size() > 0) {
			 Node fr = curr.getFirst();
			 curr.removeFirst();
			 System.out.print(fr.data + " ");
			 for(int i = 0; i < fr.children.size(); i++) {
				 next.addLast(fr.children.get(i));
			 }
			 if(curr.size() == 0) {
				 curr = next;
				 next = new LinkedList<>();
				 System.out.println();
			 }
		 }
		 
 	}
	
	public static void levelOrderLLZigZag(Node root) {
		LinkedList<Node> next = new LinkedList<>();
	    LinkedList<Node> curr = new LinkedList<>();

	    curr.addLast(root);
	    boolean l2r = true;

	    while(curr.size() > 0){
	        Node fr = curr.getFirst();
	        curr.removeFirst();
	        System.out.print(fr.data + " ");
	        if(l2r){
	            for(int i = 0; i< fr.children.size(); i++){
	                next.addFirst(fr.children.get(i));
	            }
	        } else {
	            for(int i = fr.children.size() - 1; i >= 0; i--){
	                next.addFirst(fr.children.get(i));
	            }
	        }
	        if(curr.size() == 0){
	            curr = next;
	            next = new LinkedList<>();
	            System.out.println();
	            l2r = !l2r;
	        }
	    }
	}
	 
	
	public static void main(String[] args) {
		ArrayList<Integer> dlist1 = new ArrayList<>();
		dlist1.add(10);
		dlist1.add(20);
		dlist1.add(50);
		dlist1.add(-1);
		dlist1.add(60);
		dlist1.add(-1);
		dlist1.add(-1);
		dlist1.add(30);
		dlist1.add(70);
		dlist1.add(-1);
		dlist1.add(80);
		dlist1.add(110);
		dlist1.add(-1);
		dlist1.add(120);
		dlist1.add(-1);
		dlist1.add(-1);
		dlist1.add(90);
		dlist1.add(-1);
		dlist1.add(-1);
		dlist1.add(40);
		dlist1.add(100);
		dlist1.add(-1);
		dlist1.add(-1);
		dlist1.add(-1);
		Node root = build(dlist1);
		
/*		System.out.println("Size = ----" + size(root) + "------");
		System.out.println("Max = ----" + max(root) + "------");
		System.out.println("Find  = ----" + find(root, 100) + "-----");
		System.out.println("Height = ----" + height(root) + "------");
		ArrayList<Integer> n2rpath = nodeToRootPath(root, 120);
		System.out.println("Node to root path = " + n2rpath + "------");
		System.out.println("LCA of 120, 50 is = " + lca(root, 50, 120) + "---");
		System.out.println("distance between 120, 50 is " + distance(root, 50, 120));
		System.out.println("--------------------------------");
		display(root);
		System.out.println("-----M-I-R-R-O-R-----");
		mirror(root);
		display(root); */
		
		/* 28th March 2019 */
		
//		linearize(root2);
//		display(root2);
//	    System.out.println(areSimilarStr(root, root2));
//	    System.out.println(areMirrorStr(root,root2));
		
		/* 30th March 2019 */
		
/*		heapMover h = new heapMover();
		multiSolver(root, h, 0, 68);
		preSucDe(root, h, 90);
		
		System.out.println("Height = " + h.ht);
		System.out.println("Size = " + h.sz);
		System.out.println("Maximum = " + h.mx);
		System.out.println("Minimum = " + h.mn);
		System.out.println("Ceil = " + h.cl);
		System.out.println("floor = " + h.fr);
		System.out.println("preSuccesor = " + h.preSuc);
		System.out.println("preDecessor = " + h.preDe);
*/		
		/*31st March 2019 */
		
		helper mv = new  helper();
		preSucc2(mv, root, 90);
		System.out.println(mv.pd + " " + mv.sc);
		
		System.out.println(kthLargest(root, 3));
		levelOrderLLZigZag(root);
		
	}
}
