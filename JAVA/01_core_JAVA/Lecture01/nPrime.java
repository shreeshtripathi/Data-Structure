package Lecture01;

import java.util.Scanner;

public class nPrime {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number : ");
		int n = scn.nextInt();

		for (int t = 2; t <= n; t++) {
			boolean isPrime = true;
			int d = 2;
			while (d*d <= t) {
				if (t % d == 0) {
					isPrime = false;
					break;
				}
				d++;
			}
			if (isPrime == true) {
				System.out.println(t);
			}
		}

	}

}
