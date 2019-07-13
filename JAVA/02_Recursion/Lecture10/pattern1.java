package Lecture10;

public class pattern1 {

	public static void main(String[] args) {
		Rtriangle(0, 0, 5);
	}
	
	public static void Rtriangle(int r, int c, int n) {
		if(r == n) {
			return;
		}
		System.out.print("* ");
		if(c >= r) {
			System.out.println();
			Rtriangle(r + 1, 0, n);
		}else {
			Rtriangle(r, c + 1, n);
		}
		
	}

}
