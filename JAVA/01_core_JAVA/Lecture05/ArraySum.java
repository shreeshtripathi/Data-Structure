package Lecture05;

import java.util.Scanner;

public class ArraySum {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter length of first array : ");
		int l1 = scn.nextInt();
		int[] arr1 = new int[l1];
		System.out.print("Enter length of second array : ");
		int l2 = scn.nextInt();
		int[] arr2 = new int[l2];
		int max;
		if (l1 > l2) {
			max = l1;
		} else {
			max = l2;
		}
		max += 1;
		int[] sum = new int[max];
		System.out.println("Enter first array");
		for (int i = 0; i < l1; i++) {
			arr1[i] = scn.nextInt();
		}
		System.out.println("Enter second array");
		for (int i = 0; i < l2; i++) {
			arr2[i] = scn.nextInt();
		}
		if (l1 >= l2) {
			sumArray(arr1, arr2, sum);
		} else {
			sumArray(arr2, arr1, sum);
		}
		for (int i = 0; i < max; i++) {
			System.out.print(sum[i] + " ");
		}
	}

	private static void sumArray(int[] arr1, int[] arr2, int[] sum) {
		int carry = 0;
		int len1 = arr1.length - 1;
		int len2 = arr2.length - 1;
		int s = sum.length - 1;
		while (len1 != -1 || len2 != -1 || carry != 0) {
			if (len2 >= 0) {
				int digit = arr1[len1] + arr2[len2] + carry;
				sum[s] = digit % 10;
				carry = digit / 10;
				s--;
				len1--;
				len2--;
			} else if (len1 >= 0) {
				int digit = arr1[len1] + carry;
				sum[s] = digit % 10;
				carry = digit / 10;
				s--;
				len1--;
			} else {
				sum[s] = carry;
				carry = 0;
			}

		}

		System.out.println();
	}

}
