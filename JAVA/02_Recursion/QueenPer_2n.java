
public class QueenPer_2n {
	static int count=0;
	public static void main(String[] args) {
		int[] box = new int[4];
		boolean[] tq = new boolean[3];
		qp_2n(box, 0, 0, tq);
		System.out.println(count);
	}
	
	public static void qp_2n(int[] box, int b, int qpsf, boolean[] tq) {
		if(b == box.length) {
			if(qpsf == tq.length) {
				for(int i = 0; i < box.length; i++) {
					System.out.print(box[i] + " ");
				}
				System.out.println();
				count++;
			}
			return;
		}
		box[b] = 0;
		qp_2n(box, b + 1, qpsf, tq);
		for(int q = 0; q < tq.length; q++) {
			if(tq[q] == false) {
				tq[q] = true;
				box[b] = q + 1;
				qp_2n(box, b + 1, qpsf + 1, tq);
				tq[q] = false;
			}
		}
		
	}

}
