//Code-Diamond
package Lecture02;

import java.util.Scanner;

public class pattern6 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter odd number of rows :");
		int n = scn.nextInt();
		int space = n / 2;
		int star = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < space; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k < star; k++) {
				System.out.print("*");
			}
			if (i < n / 2) {
				star += 2;
				space--;
				;
			} else {
				star -= 2;
				space++;
			}
			System.out.println();
		}

	}

}
