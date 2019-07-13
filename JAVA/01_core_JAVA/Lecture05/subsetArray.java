package Lecture05;

public class subsetArray {

	public static void main(String[] args) {
		int[] arr = { 1, 2, 3, 4 };
		for (int i = 0; i < (1 << arr.length); i++) {
			int bit = arr.length - 1;
			int j = 0;
			while (bit >= 0) {
//			for(int bit = arr.length - 1, j = 0; bit >= 0; bit--, j++) {
				int bm = 1 << bit;
				if ((i & bm) == bm) {
					System.out.print(arr[j] + " ");
				} else {
					System.out.print("* ");
				}
				bit--;
				j++;
			}
			System.out.println();
		}
	}

}
