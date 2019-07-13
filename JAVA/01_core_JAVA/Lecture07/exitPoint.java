//1.Exit point 
package Lecture07;

public class exitPoint {

	public static void main(String[] args) {
		int[][] mat = { 
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 }
		};
		int row = 0;
		int col = 0;
		int dir = 0; // 0123 - east, south, west, north
		while (row >= 0 && row < mat.length && col >= 0 && col < mat[0].length) {
			dir = (dir + mat[row][col]) % 4;
			if (dir == 0) {
				col++;
			} else if (dir == 1) {
				row++;
			} else if (dir == 2) {
				col--;
			} else if (dir == 3) {
				row--;
			}
		}
		if (dir == 0) {
			col--;
		} else if (dir == 1) {
			row--;
		} else if (dir == 2) {
			col++;
		} else if (dir == 3) {
			row++;
		}
		System.out.println("x = " + row + " y = " + col);

	}

}
