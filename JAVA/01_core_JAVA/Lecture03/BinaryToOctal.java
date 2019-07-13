package Lecture03;

import java.util.Scanner;

public class BinaryToOctal {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter an Binary number :");
		int binary = scn.nextInt();
		int octal = 0;
		int p = 1;
		while (binary != 0) {
			int rem = binary % 1000;
			binary = binary / 1000;
			switch (rem) {
			case 0: {
				octal = (0 * p) + octal;
				break;
			}
			case 1: {
				octal = (1 * p) + octal;
				break;
			}
			case 10: {
				octal = (2 * p) + octal;
				break;
			}
			case 11: {
				octal = (3 * p) + octal;
				break;
			}
			case 100: {
				octal = (4 * p) + octal;
				break;
			}
			case 101: {
				octal = (5 * p) + octal;
				break;
			}
			case 110: {
				octal = (6 * p) + octal;
				break;
			}
			case 111: {
				octal = (7 * p) + octal;
				break;
			}
			}
			p = p * 10;
		}
		System.out.print(octal);
	}

}
