package Lecture05;

public class ReverseArray {

	public static void main(String[] args) {
		int[] arr = { 10, 20, 30, 40, 50 };
		int right = arr.length - 1;
		int left = 0;
		while (left < right) {
			// if two numbers are same  then this logic doesn't work
			// we have to make a temp variable then
			arr[left] = arr[left] ^ arr[right];
			arr[right] = arr[left] ^ arr[right];
			arr[left] = arr[left] ^ arr[right];
			left++;
			right--;
		}

		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
