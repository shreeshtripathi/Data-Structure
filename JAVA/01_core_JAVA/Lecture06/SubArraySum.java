//1.Kadan's Algorithm
package Lecture06;

import java.util.Scanner;

public class SubArraySum {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] arr = { 2, 3, 6, -1, -12, 3, -4, 5, 19 };
		int max = Integer.MIN_VALUE;// It take minimum value of an integer.
		int sum = arr[0];
		int cstart = 0;
		int cend = 0;
		int mstart = 0;
		int mend = 0;
		for (int i = 1; i < arr.length; i++) {

			if (sum > 0) {
				cend = i;
				sum = sum + arr[i];
			} else {
				cstart = i;
				cend = i;
				sum = arr[i];
			}
			if (max < sum) {
				max = sum;
				mstart = cstart;
				mend = cend;

			}

		}
		for (int i = mstart; i <= mend; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		System.out.println(max);

	}

}
