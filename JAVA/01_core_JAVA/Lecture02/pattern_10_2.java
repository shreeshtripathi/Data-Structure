package Lecture02;
import java.util.Scanner;

public class pattern_10_2 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number of rows : ");
		int row = scn.nextInt();
		int var = 1;
		for (int i = 1; i <= row; i++) {
			var = 1;
			for (int j = 1; j <= 2 * row - 1; j++) {
				if (j <= i || (i + j) >= 2 * row) {
					System.out.print(var + " ");
					if (j < i) {
						var++;
					} else {
						var--;
					}
				} else {
					System.out.print("  ");
				}
			}
			System.out.println();
		}
	}

}
