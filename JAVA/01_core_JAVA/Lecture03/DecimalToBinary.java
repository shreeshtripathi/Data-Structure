package Lecture03;

import java.util.Scanner;

public class DecimalToBinary {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the decimal number:");
		int n = scn.nextInt();
		int binary = 0;
		int power = 1;
		while (n != 0) {
			int rem = n % 2;
			binary = binary + (rem * power);
			power = power * 10;
			n = n / 2;
		}
		System.out.println(binary);
	}

}
