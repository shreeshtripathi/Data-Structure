package Lecture15;

public class changeCoinComb {

	public static void main(String[] args) {
		int[] arr = {2, 3, 5};
		ccc(arr, 7, 0, "");

	}
	
	public static void ccc(int[] arr, int amt, int li, String asf) {
		if (amt == 0) {
			System.out.println(asf);
			return;
		}

		for (int i = li; i < arr.length; i++) {
			if (arr[i] <= amt) {
				ccc(arr, amt - arr[i], i,  asf + arr[i]);
			}
		}
	}

}
