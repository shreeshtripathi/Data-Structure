package Lecture15;

public class changeCoinPerm {

	public static void main(String[] args) {
		int[] arr = { 2, 3, 5 };
		ccp(arr, 7, "");
	}

	public static void ccp(int[] arr, int amt, String asf) {
		if (amt == 0) {
			System.out.println(asf);
			return;
		}

		for (int i = 0; i < arr.length; i++) {
			if (arr[i] <= amt) {
				ccp(arr, amt - arr[i], asf + arr[i]);
			}
		}
	}

}
