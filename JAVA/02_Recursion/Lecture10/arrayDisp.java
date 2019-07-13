package Lecture10;

public class arrayDisp {

	public static void main(String[] args) {
		int[] arr = {2, 9, 3, 7, 1};
		display(arr, 0);
	}
	
	public static void display(int[] arr, int sp) {
		if(sp == arr.length) {
			return;
		}
		System.out.print(arr[sp] + " ");
		display(arr, sp + 1);
	}

}
