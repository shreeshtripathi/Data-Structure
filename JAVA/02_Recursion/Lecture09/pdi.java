package Lecture09;

public class pdi {

	public static void main(String[] args) {
		pdi(6);
	}
	public static void pdi(int n) {
		if(n == 0) {
			return;
		}
		System.out.print(n + " ");
		pdi(n - 1);
		System.out.print(n + " ");
	}

}
