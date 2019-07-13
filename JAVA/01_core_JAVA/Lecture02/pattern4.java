//Code-Pascal Triangle from binomial formula 
package Lecture02;

import java.util.Scanner;

public class pattern4 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number of rows :");
		int n = scn.nextInt();
		for (int i = 0; i < n; i++) {
			int num = 1;
			for (int j = 0; j <= i; j++) {
				System.out.print(num + " ");
				// nC(k+1)=nCk*(n-k)/(k+1)
				num = (num * (i - j)) / (j + 1);
			}
			System.out.println();
		}

	}

}
