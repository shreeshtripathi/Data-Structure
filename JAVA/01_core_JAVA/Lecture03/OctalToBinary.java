package Lecture03;

import java.util.Scanner;

public class OctalToBinary {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter an octal number :");
		int oc = scn.nextInt();
		int bin = 0;
		int p = 1;
		while (oc != 0) {
			int rem = oc % 10;
			oc = oc / 10;
			switch (rem) {
			case 0: {
				bin = (0 * p) + bin;
				break;
			}
			case 1: {
				bin = (1 * p) + bin;
				break;
			}
			case 2: {
				bin = (10 * p) + bin;
				break;
			}
			case 3: {
				bin = (11 * p) + bin;
				break;
			}
			case 4: {
				bin = (100 * p) + bin;
				break;
			}
			case 5: {
				bin = (101 * p) + bin;
				break;
			}
			case 6: {
				bin = (110 * p) + bin;
				break;
			}
			case 7: {
				bin = (111 * p) + bin;
				break;
			}
			}
			p = p * 1000;
		}
		System.out.print(bin);
	}

}
