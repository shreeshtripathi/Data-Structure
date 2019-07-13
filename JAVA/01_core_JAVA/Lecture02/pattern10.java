package Lecture02;

import java.util.Scanner;

public class pattern10 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number of rows:");
		int n = scn.nextInt();
		int var;
		int space = n;
		for (int row = 1; row <= n; row++) {
			for (int j = 1; j <= row; j++) {
				var = j;
				System.out.print(var + " ");
			}
			space--;
			for (int k = 2 * space - 1; k > 0; k--) {
				System.out.print("- ");
			}
			var = row;
			int num = row;
			if (row == n) {
				var--;
				num--;
			}
			for (int l = 1; l <= num; l++) {
				System.out.print(var + " ");
				var--;
			}
			System.out.println();
		}
	}
}