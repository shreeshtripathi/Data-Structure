package Lecture05;

import java.util.Scanner;

public class BinarySearch {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80 };
		System.out.print("Enter number to find in array :");
		int num = scn.nextInt();
		int start = 0;
		int end = arr.length - 1;
		int mid = (start + end) / 2;
		while (end >= start) {
			if (num > arr[mid]) {
				start = mid + 1;
			}
			if (num < arr[mid]) {
				end = mid - 1;
			}
			if (arr[mid] == num) {
				System.out.println(mid);
				return;
			}
			mid = (start + end) / 2;
		}

		System.out.println(-1);
	}

}
