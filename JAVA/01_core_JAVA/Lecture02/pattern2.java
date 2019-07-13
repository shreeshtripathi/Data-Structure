//Code-Right angled triangle for number
package Lecture02;

import java.util.Scanner;

public class pattern2 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Please Enter a number: ");
		int n = scn.nextInt();
		int num = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				System.out.print(num + "  ");
				num++;
			}
			System.out.println();
		}

	}

}
