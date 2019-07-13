package Lecture05;

public class InverseArray {

	public static void main(String[] args) {
		int[] arr = { 2, 4, 1, 0, 3 };
		int[] inv = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			inv[arr[i]] = i;
		}

		for (int val : inv) {
			System.out.print(val + " ");
		}
	}

}
