package Lecture05;

import java.util.Scanner;

public class rotateArray {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a number: ");
		int n = scn.nextInt();
		scn.close();
		int[] arr = { 10, 20, 30, 40, 50, 60, 70, 80 };
		reverse(arr, 0, arr.length - 1); // full array rotate
		reverse(arr, 0, n - 1); // rotate part 1
		reverse(arr, n, arr.length - 1); // rotate part 2
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	private static void reverse(int[] a, int lo, int hi) {
		for (int left = lo, right = hi; left < right; left++, right--) {
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}

}
