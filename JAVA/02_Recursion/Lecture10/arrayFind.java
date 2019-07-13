package Lecture10;

public class arrayFind {

	public static void main(String[] args) {
		int[] arr = {2, 9, 3, 7, 1};
		boolean val = findStupid(arr, 0, 9);
		System.out.println(val);
		val = findSmart(arr, 0, 10);
		System.out.println(val);
	}
	//It call first from 0 to end then reverse and check the availability
	public static boolean findStupid(int[] arr, int sp, int data) {
		if(sp == arr.length) {
			return false;
		}
		boolean f = findStupid(arr, sp + 1, data);
		if(f == true) {
			return true;
		} else if (arr[sp] == data){
			return true;
		} else {
			return false;
		}
	}
	
	// It check the current index and then check for last
	public static boolean findSmart(int[] arr, int sp, int data) {
		if(sp == arr.length) {
			return false;
		}
		if(arr[sp] == data) {
			return true;
		}
		boolean f = findSmart(arr, sp + 1, data);
		return f;
	}

}
