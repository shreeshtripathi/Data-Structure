//Take a number and position from user
package Lecture04;

import java.util.Scanner;

public class OffBit {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number :");
		int num = scn.nextInt();
		System.out.println("Entered number is " + Integer.toBinaryString(num));
		System.out.print("Enter Poition :");
		int k = scn.nextInt();
		int bm = 1 << k;
		if ((num & bm) == 0) {
			System.out.println("Bit is already OFF");
		} else {
			num = (num & ~bm);
			System.out.println("After OFF, number is :" + num);
			System.out.println(Integer.toBinaryString(num));
		}
	}

}
