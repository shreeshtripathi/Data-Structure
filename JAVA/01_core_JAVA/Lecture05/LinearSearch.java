package Lecture05;

import java.util.Scanner;

public class LinearSearch {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] arr = { 12, 2, 3, 4, 5, 6 };
		System.out.print("Enter a number :");
		int num = scn.nextInt();
		// int result = 0;
		// int index = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == num) {
				// result = 1;
				// index = i;
				// break;
				System.out.println(i);
				return;
			}
		}
//		if(result == 1) {
//			System.out.println("Number is present at "+index);
//			return;
//		}
//		else {
//			System.out.println("Number is not in array.");
//		}
		System.out.println(-1);
	}

}
