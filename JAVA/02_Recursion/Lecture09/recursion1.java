//print decreases 
package Lecture09;

public class recursion1 {
	public static void main(String[] args) {
		pd(5);
	}
	private static void pd(int n) {
		if(n == 0) {
			return;
		}
		System.out.print(n + " ");
		pd(n - 1);
	}
}
