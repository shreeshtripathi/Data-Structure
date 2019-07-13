package Lecture09;

public class towerOfHanoi {

	public static void main(String[] args) {
		toh('s', 'd', 'h', 2);
	}
	
	public static void toh(char s, char d, char h, int n) {
		if(n == 0) {
			return;
		}
		toh(s, h, d, n - 1);
		System.out.println(n + " move from " + s + " to  " + d);
		toh(h, d, s, n - 1);
	}

}
