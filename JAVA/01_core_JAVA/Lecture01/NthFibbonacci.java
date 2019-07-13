package Lecture01;

import java.util.Scanner;

public class NthFibbonacci {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter a number:");
		int n = scn.nextInt();
		scn.close();
		int a = 0, b = 1, c = 0, count = 0;
		while (count != n) {
			c = a + b;
			a = b;
			b = c;
			count++;

		}
		System.out.println(a);
	}

}
