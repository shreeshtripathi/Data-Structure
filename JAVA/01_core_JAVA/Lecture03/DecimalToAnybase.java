package Lecture03;

import java.util.Scanner;

public class DecimalToAnybase {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter decimal number:");
		int dec = scn.nextInt();
		System.out.print("Enter base :");
		int base = scn.nextInt();
		int ans = 0;
		int power = 1; // base to the power 0
		while (dec != 0) {
			int rem = dec % base;
			ans = ans + (rem * power);
			power = power * 10;
			dec = dec / base;
		}
		System.out.println(ans);
	}

}
