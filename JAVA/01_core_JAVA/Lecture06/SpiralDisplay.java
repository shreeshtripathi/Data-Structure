//Take a 2-D array from user and print it in spiral manners 
package Lecture06;

import java.util.Scanner;

public class SpiralDisplay {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number of rows and column :");
		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] mat = new int[row][col];
		System.out.println("Enter elements in matrics :");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat[i][j] = scn.nextInt();
			}
		}
		System.out.println("Spiral display of entered matrics is :");
		int rmin = 0; // Lower Wall
		int rmax = row - 1; // Right Wall
		int cmin = 0; // Bottom Wall
		int cmax = col - 1; // Upper Wall
		int element = row * col;
		while (element != 0) {
			if (element > 0) {
				for (int i = rmin; i <= rmax; i++) {
					System.out.print(mat[i][cmin] + ", ");
					element--;
				}
				cmin++;
			}
			if (element > 0) {
				for (int i = cmin; i <= cmax; i++) {
					System.out.print(mat[rmax][i] + ", ");
					element--;
				}
				rmax--;
			}
			if (element > 0) {
				for (int i = rmax; i >= rmin; i--) {
					System.out.print(mat[i][cmax] + ", ");
					element--;
				}
				cmax--;
			}
			if (element > 0) {
				for (int i = cmax; i >= cmin; i--) {
					System.out.print(mat[rmin][i] + ", ");
					element--;
				}
				rmin++;
			}
		}
	}

}
