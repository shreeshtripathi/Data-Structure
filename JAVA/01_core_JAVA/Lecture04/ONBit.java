package Lecture04;

import java.util.Scanner;

public class ONBit {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number :");
		int num = scn.nextInt();
		System.out.println(Integer.toBinaryString(num));
		System.out.print("Enter Poition :");
		int k = scn.nextInt();
		int bm = 1 << k;
		if ((num & bm) == bm) {
			System.out.println("Bit is already ON");
		} else {
			num = (num | bm);
			System.out.println("After ON the bit, number is : " + num);
		}
	}

}
