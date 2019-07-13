package Lecture14;

public class combqueen {

	public static void main(String[] args) {
		// comb2n(2, 4, 0, 0, "");
		combDiv(-1, 0, 1, 2, 4, "");

	}

	public static void comb2n(int tq, int tb, int qsf, int cb, String asf) {

		if (cb == tb) {
			if (qsf == tq) {
				System.out.println(asf);
			}
			return;
		}
		comb2n(tq, tb, qsf + 1, cb + 1, asf + "q" + qsf + "b" + cb + " ");
		comb2n(tq, tb, qsf, cb + 1, asf);

	}

	public static void combDiv(int lqwpiwb, int bm, int cq, int tq, int tb, String asf) {

		if (cq > tq) {
			System.out.println(asf);
			return;
		}
		// lqwpiwb = last queen was placed in which box

		for (int cb = lqwpiwb + 1; cb < tb; cb++) {
			if ((bm & (1 << cb)) == 0) {
				bm = bm ^ (1 << cb);
				combDiv(cb, bm, cq + 1, tq, tb, asf + "q" + cq + "b" + cb + " ");
				bm = bm ^ (1 << cb);
			}
		}

	}

}
