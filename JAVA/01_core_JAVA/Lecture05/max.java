package Lecture05;

public class max {

	public static void main(String[] args) {
		int[] arr = { 2, 12, 65, 2, 7, 98, 100 };
		int max = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		System.out.println(max);
	}

}
