package Lecture01;

import java.util.Scanner;

public class ReverseNumber {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number :");
		int n = scn.nextInt();
		int New = 0;
		while (n != 0) {
			New = (New * 10) + n % 10;
			n = n / 10;
		}
		System.out.println(New);

	}

}