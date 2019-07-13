  package Lecture13;

public class queenPermutation {

	public static void main(String[] args) {
		boolean[] boxes = new boolean[5];
		qpermute(boxes, 1, 2,"");
	}
	
	public static void qpermute(boolean[] boxes, int cq, int tq, String asf) {
		
		if(cq > tq) {
			System.out.println(asf);
			return;
		}
		
		for(int i = 0; i < boxes.length; i++) {
			if(boxes[i] == false) {
				boxes[i] = true;
				qpermute(boxes, cq + 1, tq, asf + "q" + cq + "b" + i + " ");
				boxes[i] = false;
			}
			
		}
	}

}
