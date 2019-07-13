package Lecture05;

public class FunWithArray {

	public static void main(String[] args) {
		int[] arr1 = new int[4];
		arr1[0] = 10;
		arr1[1] = 20;
		arr1[2] = 30;
		arr1[3] = 40;

		int[] arr = { 10, 20, 30, 40 };

		for (int i = 0; i < arr.length; i++) {
			if (i == 0) {
				System.out.println("array 1    array 2");
			}
			System.out.println("  " + arr[i] + "   \t  " + arr1[i]);
		}
	}

}
