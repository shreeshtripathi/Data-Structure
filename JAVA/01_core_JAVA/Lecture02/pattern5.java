//Code-Make a cross
package Lecture02;

import java.util.Scanner;

public class pattern5 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter odd number of rows :");
		int n = scn.nextInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// check the available position in square
				if (i == j || (i + j) == n - 1) {
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}

	}

}
