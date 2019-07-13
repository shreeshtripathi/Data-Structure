package Lecture10;

public class pattern2 {

	public static void main(String[] args) {
		Itriangle(0, 0, 5);
	}

	public static void Itriangle(int r, int c, int n) {
		if (r == n) {
			return;
		}
		System.out.print("* ");
		if (c < n - r) {
			Itriangle(r, c + 1, n);
		} else {
			System.out.println();
			Itriangle(r + 1, 0, n);
		}

	}

}
