//Code- Number diamond
package Lecture02;

import java.util.Scanner;

public class pattern8 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the number of rows:");
		int n = scn.nextInt();
		int column = 1, InitialNum = 1, space = n / 2;
		int myNum = 1;
		for (int row = 0; row < n; row++) {
			for (int j = 0; j < space; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k < column; k++) {
				System.out.print(myNum);
				if (k < column / 2) {
					myNum++;
				} else {
					myNum--;
				}
			}
			if (row < n / 2) {
				column += 2;
				space--;
				InitialNum++;

			} else {
				column -= 2;
				space++;
				InitialNum--;
			}
			myNum = InitialNum;
			System.out.println();
		}

	}

}
