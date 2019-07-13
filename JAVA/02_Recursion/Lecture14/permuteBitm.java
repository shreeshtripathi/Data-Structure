package Lecture14;

public class permuteBitm {

	public static void main(String[] args) {
		pqwbm(0, 1, 2, 5, "");
	}
	
	public static void pqwbm(int bm, int cq, int tq, int tb, String asf) {
		
		if(cq > tq) {
			System.out.println(asf);
			return;
		}
		
		for(int cb = 0; cb < tb; cb++) {
			if((bm & (1 << cb)) == 0) {
				bm = bm ^ (1 << cb);
				pqwbm(bm, cq + 1, tq, tb, asf + "q" + cq + "b" + cb + " ");
				bm = bm ^ (1 << cb);
			}
		}
		
	}

}
