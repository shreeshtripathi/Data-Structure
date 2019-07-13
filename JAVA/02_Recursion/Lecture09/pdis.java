package Lecture09;

public class pdis {

	public static void main(String[] args) {
		pdiss(7);
	}
	public static void pdiss(int n) {
		if(n == 0) {
			return;
		}
		if(n % 2 != 0) {
			System.out.print(n + " ");
		}
		pdiss(n - 1);
		if(n % 2 == 0) {
			System.out.print(n + " ");
		}
	}

}
