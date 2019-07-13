package Lecture05;

import java.util.Scanner;

public class BinarySr_last {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] arr = { 10, 10, 10, 20, 30, 40, 50, 60, 70, 80 };
		System.out.print("Enter number to find in array :");
		int num = scn.nextInt();
		int start = 0;
		int end = arr.length - 1;
		int mid = (start + end) / 2;
		int result = -1;
		while (end >= start) {
			if (num > arr[mid]) {
				start = mid + 1;
			} else if (num < arr[mid]) {
				end = mid - 1;
			} else {
				result = mid;
				start = mid + 1;
			}
			mid = (start + end) / 2;
		}

		System.out.println(result);
	}

}
