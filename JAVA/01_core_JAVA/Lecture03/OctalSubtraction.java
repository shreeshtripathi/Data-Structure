package Lecture03;

import java.util.Scanner;

public class OctalSubtraction {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the first number :");
		int first = scn.nextInt();
		System.out.print("Enter second number :");
		int second = scn.nextInt();
		scn.close();
		int bor = 0;
		int diff = 0;
		int power = 1;
		while (first != 0) {
			int rem1 = first % 10;
			first /= 10;
			int rem2 = second % 10;
			second = second / 10;
			rem1 = rem1 + bor;
			if (rem1 >= rem2) {
				bor = 0;
			} else {
				bor = -1;
				rem1 = rem1 + 8;
			}
			int d = rem1 - rem2;
			diff = diff + d * power;
			power = power * 10;
		}
		System.out.println(diff);
	}

}
