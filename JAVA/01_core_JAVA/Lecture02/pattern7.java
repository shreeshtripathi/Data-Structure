//Code-Hollow Diamond
package Lecture02;

import java.util.Scanner;

public class pattern7 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter odd number of rows :");
		int n = scn.nextInt();
		int stars = n / 2 + 1;
		int space = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < stars; j++) {
				System.out.print("@ ");
			}
			for (int k = 0; k < space; k++) {
				System.out.print("  ");
			}
			for (int j = 0; j < stars; j++) {
				System.out.print("@ ");
			}
			if (i < n / 2) {
				space += 2;
				stars--;
			} else {
				space -= 2;
				stars++;
			}
			System.out.println();
		}

	}

}
