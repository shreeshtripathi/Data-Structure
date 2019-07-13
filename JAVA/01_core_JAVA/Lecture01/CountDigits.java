package Lecture01;

import java.util.Scanner;

public class CountDigits {

	public static void main(String[] args) {
		Scanner scn=new Scanner(System.in);
		System.out.print("Enter the Digit :");
		int n=scn.nextInt();
		scn.close();
		int count=0;
		while(n!=0) {
			count++;
			n=n/10;
		}
		System.out.println(count);

	}

}