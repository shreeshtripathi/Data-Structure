package Lecture09;

public class factorial {

	public static void main(String[] args) {
		int num = fact(5);
		System.out.println(num);
	}
	public static int fact(int n) {
		if(n == 0) {
			return 1;
		}
		return n * fact(n - 1);
	}

}
