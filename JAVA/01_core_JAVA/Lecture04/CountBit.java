// Take a number from user and count the number of 1's in the binary form.
package Lecture04;

import java.util.Scanner;

public class CountBit {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number :");
		int num = scn.nextInt();
		scn.close();
		System.out.println(Integer.toBinaryString(num));
		int count = 0;
		while (num != 0) {
			int rsbm = (num & (-num));
			count++;
			num = num - rsbm;
		}
		System.out.println(count);
	}

}
