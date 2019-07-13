package Lecture04;

import java.util.Scanner;

public class XOR {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number :");
		int num = scn.nextInt();
		System.out.print("Enter Poition :");
		int k = scn.nextInt();
		int bm = 1 << k;
		System.out.println(Integer.toBinaryString(num));
		num = num ^ bm;
		System.out.println(Integer.toBinaryString(num));
		System.out.println(num);
	}

}
