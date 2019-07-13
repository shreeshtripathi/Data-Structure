package Lecture03;

import java.util.Scanner;

public class OctalAddition {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter first octal number :");
		int first = scn.nextInt();
		System.out.print("Enter second octal number :");
		int second = scn.nextInt();
		scn.close();
		int carry = 0;
		int sum = 0;
		int power = 1;
		while (first != 0 || second != 0 || carry != 0) {
			int rem1 = first % 10;
			first = first / 10;
			int rem2 = second % 10;
			second = second / 10;
			int r = rem1 + rem2 + carry;
			int d = r % 8;
			carry = r / 8;
			sum = sum + d * power;
			power = power * 10;
		}
		System.out.println(sum);
	}

}
