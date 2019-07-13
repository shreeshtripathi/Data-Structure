//Make a table from 'start' to 'end' increment by 'step' and print far. to celcius
package Lecture04;

import java.util.Scanner;

public class FahrenheitToCelcius {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter initial value :");
		int in = scn.nextInt();
		System.out.print("Enter Final value :");
		int fin = scn.nextInt();
		System.out.print("Enter step value :");
		int step = scn.nextInt();
		for (int i = in; i <= fin; i = i + step) {
			// 5.0 is convert this data type into double data type
			// double divide by integer is double because integer convert into double
			// step by step every data type convert into double
			int cel = (int) (5 / 9.0 * (i - 32));
			System.out.println(i + "  =  " + cel);
		}
	}

}
