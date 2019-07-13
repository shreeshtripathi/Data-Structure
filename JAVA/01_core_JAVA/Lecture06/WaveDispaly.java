package Lecture06;

import java.util.Scanner;

public class WaveDispaly {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number of rows and column :");
		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] mat = new int[row][col];
		//int[][] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		System.out.println("Enter elements in matrics :");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				mat[i][j] = scn.nextInt();
			}
		}
		System.out.println("Wave display of entered matrics is :");
		for(int c = 0; c < col; c++) {
			if(c % 2 == 0) {
				for(int r = 0; r < row; r++) {
					System.out.print(mat[r][c]+", ");
				}
			}
			else {
				for(int r = row-1; r >= 0; r--) {
					System.out.print(mat[r][c]+ ", ");
				}
			}
		}

	}

}
