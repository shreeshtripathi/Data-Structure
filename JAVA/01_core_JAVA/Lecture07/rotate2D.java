package Lecture07;

public class rotate2D {

	public static void main(String[] args) {
		int[][] mat = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
		};
		int r = mat.length;
		int c = mat[0].length;
		for(int i = 0; i < c; i++) {
			for(int  j = i; j < r; j++) {
				int temp = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = temp;
			}
		}
		
		for(int i = 0; i < c; i++) {
			int le = 0; // left
			int ri = mat[i].length - 1;  //right
			while(le <= ri) {
				int temp = mat[i][le];
				mat[i][le] = mat[i][ri];
				mat[i][ri] = temp;
				le++;
				ri--;
			}
		}
		
		for(int i = 0; i < c; i++) {
			for(int  j = 0; j < r; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
