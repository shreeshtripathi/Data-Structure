package Lecture03;

import java.util.Scanner;

public class BinaryToDecimal {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the Binary number:");
		int n = scn.nextInt();
		int decimal = 0;
		int power = 1;
		while (n > 0) {
			int rem = n % 10;
			decimal = decimal + (rem * power);
			power = power * 2;
			n = n / 10;
		}
		System.out.println(decimal);
	}

}
