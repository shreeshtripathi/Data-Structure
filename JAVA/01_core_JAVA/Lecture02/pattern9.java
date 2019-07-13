//Print the value present in an array in vertical manners
//just like graph
package Lecture02;

import java.util.Scanner;

public class pattern9 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Graph is :\n");
		int[] arr = { 2, 7, 3, 4, 5 };
		// Find max in the array
		// Take first element is greater ad check rest of element
		int max = arr[0];
		for (int i = 1; i <= 4; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		// Check condition for deserving
		for (int i = 1; i <= max; i++) {
			for (int j = 0; j <= 4; j++) {
				if (i >= (max - arr[j] + 1)) {
					System.out.print("|*| ");
				} else {
					System.out.print("    ");
				}
			}
			System.out.println();
		}

	}

}
