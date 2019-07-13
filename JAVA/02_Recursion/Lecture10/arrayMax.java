package Lecture10;

public class arrayMax {

	public static void main(String[] args) {
		int[] arr = {2, 9, 3, 15, 1};
		int val = max(arr, 0);
		System.out.println(val);
	}
	public static int max(int[] arr, int sp) {
		if(sp == arr.length - 1) {
			return arr[sp];
		}
		int max1 = max(arr, sp + 1);
		if(max1 < arr[sp]) {
			return arr[sp];
		}
		return max1;
	}
}
