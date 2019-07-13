package Lecture03;

import java.util.Scanner;

public class AnyBaseToDecimal {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter number:");
		int num = scn.nextInt();
		System.out.print("Enter base :");
		int base = scn.nextInt();
		scn.close();
		int ans = 0;
		int basep = 1; // base to the power 0
		while (num != 0) {
			int rem = num % 10;
			ans = ans + (rem * basep);
			basep = basep * base;
			num = num / 10;
		}
		System.out.println(ans);
	}

}
