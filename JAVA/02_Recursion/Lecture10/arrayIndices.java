package Lecture10;

public class arrayIndices {

	public static void main(String[] args) {
		int[] arr = {2, 11, 3, 11, 11, 9, 7, 4, 11};
		int val = findlast(arr, 0, 11);
		System.out.println(val);
		val = findfirst(arr, 0, 11);
		System.out.println(val);
	}
	public static int findlast(int[] arr, int sp, int data) {
		if(sp == arr.length) {
			return -1;
		}
		int index = findlast(arr, sp + 1, data);
		if(index != -1) {
			return index;
		} else if(arr[sp] == data) {
			return sp;
		} else {
			return -1;
		}
	}
	
	public static int findfirst(int[] arr, int sp, int data) {
		if(sp == arr.length) {
			return -1;
		}
		if(arr[sp] == data) {
			return sp;
		}
		int index = findfirst(arr, sp + 1, data);
		return index;
	}

}
