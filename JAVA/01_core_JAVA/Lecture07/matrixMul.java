//2. Matrix Multiplication
package Lecture07;

public class matrixMul {

	public static void main(String[] args) {
		int[][] one = {
				{10, 0, 0},
				{0, 10, 1}
		};
		int[][] two = {
				{1, 0, 1, 0},
				{0, 1, 1, 1},
				{1, 1, 1, 1}
		};
		int r1 = one.length;
		int c1 = one[0].length;
		int r2 = two.length;
		int c2 = two[0].length;
		if(c1 != r2) {
			System.out.println("For matrix multiplication c1 and r2 must be equal");
			return;
		}
		int[][] prd = new int[r1][c2];
		for(int i = 0; i < r1; i++) {
			for(int j = 0; j < c2; j++) {
				for(int k = 0; k < c1; k++) {
					prd[i][j] += one[i][k] * two[k][j];
				}
			}
		}
		for(int  i =0; i < r1; i++) {
			for(int j = 0; j < c2; j++) {
				System.out.print(prd[i][j]+ " ");
			}
			System.out.println();
		}
	}

}
