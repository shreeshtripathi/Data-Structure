package Lecture10;

public class allIndices {

	public static void main(String[] args) {
		int[] arr = {2, 11, 3, 11, 11, 9, 7, 4, 11};
		int[] data = allI(arr, 0, 11, 0);
		for(int i = 0; i < data.length; i++) {
			System.out.print(data[i] + " ");
		}
	}
	
	public static int[] allI(int[] arr,int sp, int data, int len) {
		if(sp == arr.length) {
			return new int[len];
		}
		if(arr[sp] == data) {
			len++;
		}
		int[] index = allI(arr, sp + 1, data, len);
		if(arr[sp] == data) {
			index[len - 1] = sp;
		}
		return index;
		
	}

}
