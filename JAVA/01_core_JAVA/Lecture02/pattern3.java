//Code-Right angled triangle from fibonacci series
package Lecture02;

import java.util.Scanner;

public class pattern3 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Please Enter a number: ");
		int n = scn.nextInt();
		int a = 0, b = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				System.out.print(a + "  ");
				int c = a + b;
				a = b;
				b = c;
			}
			System.out.println();
		}
	}

}
