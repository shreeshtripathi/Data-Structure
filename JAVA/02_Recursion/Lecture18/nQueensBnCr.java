
//Code- nCr style, problem is nQueens in which boards are at level

package Lecture18;

public class nQueensBnCr {

	public static void main(String[] args) {
		int[][] bd = new int[4][4];
		nq_bncr(bd, 0, 0);
	}
	
	public static boolean isSafe(int[][] bd, int i, int j) {
		// north
		for(int ci = i - 1, cj = j; ci >= 0; ci--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south
		for(int ci = i + 1, cj = j; ci < bd.length; ci++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// east
		for(int ci = i, cj = j + 1; cj < bd.length; cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// west
		for(int ci = i, cj = j - 1; cj >= 0; cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// north - west
		for(int ci = i - 1, cj = j - 1; ci >= 0 && cj >= 0; ci--, cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// north - east
		for(int ci = i - 1, cj = j + 1; ci >= 0 && cj < bd.length; ci--, cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south - east
		for(int ci = i + 1, cj = j + 1; ci < bd.length && cj < bd.length; ci++, cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south - west
		for(int ci = i + 1, cj = j - 1; cj >= 0 && ci < bd.length; ci++, cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void nq_bncr(int[][] bd, int b, int qpsf) {
		
		if(b == bd.length * bd.length) {
			if(qpsf == bd.length) {
				for(int i = 0; i < bd.length; i++) {
					for(int j = 0; j < bd.length; j++) {
						System.out.print(bd[i][j] + " ");
					}
					System.out.println();
				}
				System.out.println("= = = =");
			}
			return;
			
		}
		
		nq_bncr(bd, b + 1, qpsf);
		int i = b / bd.length;
		int j = b % bd.length;
		if(bd[i][j] == 0 && isSafe(bd, i, j)) {
			bd[i][j] = qpsf + 1;
			nq_bncr(bd, b + 1, qpsf + 1);
			bd[i][j] = 0;
		}
	}

}
