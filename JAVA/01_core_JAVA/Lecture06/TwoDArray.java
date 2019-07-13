package Lecture06;

import java.util.Scanner;

public class TwoDArray {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter rows and column :");
		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] mat = new int[row][col];
		System.out.println("Enter Matrics :");
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				mat[r][c] = scn.nextInt();
			}
		}
		// Printing of 2 D array
		System.out.println("Entered matrics is :");
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				System.out.print(mat[r][c] + " ");
			}
			System.out.println();
		}
	}

}