package Lecture01;

import java.util.Scanner;

public class isPrime {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a number to check it is prime");
		int n = scn.nextInt();
		scn.close();
		if (n == 1) {
			System.out.println("1 is neither prime nor composite");
		} else {
			int j = 2;
			while ((j*j) <= n) {
				if (n % j == 0) {
					System.out.println("Composite");
					return;
				}
				j++;
			}
			System.out.println("Prime");
		}
	}

}
