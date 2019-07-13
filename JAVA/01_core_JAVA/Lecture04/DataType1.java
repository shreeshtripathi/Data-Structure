//Take a character from user
//If character is in lower case, print 'LOWER CASE' and convert into upper case
//If character is in upper case, print 'UPPER CASE' and convert into lower case 
package Lecture04;

import java.util.Scanner;

public class DataType1 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the Character :");
		char ch = scn.next().charAt(0);

		if (ch >= 'A' && ch <= 'Z') {
			System.out.println("Entered character is Upper Case");
			char lc = (char) ('a' + (ch - 'A'));
			System.out.println("Lowercase character is : " + lc);
		} else if (ch >= 'a' && ch <= 'z') {
			System.out.println("Entered character is Lower Case");
			char uc = (char) ('A' + (ch - 'a'));
			System.out.println("Uppercase character is : " + uc);

		}
	}

}
