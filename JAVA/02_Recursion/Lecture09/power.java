package Lecture09;

public class power {

	public static void main(String[] args) {
		int val = powers(5, 3);
		System.out.println(val);
	}
	public static int powers(int num, int pow) {
		if(pow == 0) {
			return 1;
		}
		return num * powers(num, pow - 1);
	}

}
