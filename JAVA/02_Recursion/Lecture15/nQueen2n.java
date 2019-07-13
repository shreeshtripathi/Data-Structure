package Lecture15;

public class nQueen2n {

	public static void main(String[] args) {
		boolean[][] board = new boolean[4][4];
		nqueen(board, 0, 0, "");
	}

	public static boolean isQueenSafe(boolean[][] board, int i, int j) {

		// north;
		for (int ci = i - 1, cj = j; ci >= 0; ci--) {
			if (board[ci][cj] == true) {
				return false;
			}
		}
		// south;
		for (int ci = i + 1, cj = j; ci < board.length; ci++) {
			if (board[ci][cj] == true) {
				return false;
			}
		}
		// east
		for (int ci = i, cj = j + 1; cj < board.length; cj++) {
			if (board[ci][cj] == true) {
				return false;
			}
		}

		// west
		for (int ci = i, cj = j - 1; cj >= 0; cj--) {
			if (board[ci][cj] == true) {
				return false;
			}
		}

		// north - east

		for (int ci = i - 1, cj = j + 1; ci >= 0 && cj < board.length; ci--, cj++) {
			if (board[ci][cj] == true) {
				return false;
			}
		}

		// south - east
		for (int ci = i + 1, cj = j + 1; ci < board.length && cj < board.length; ci++, cj++) {
			if (board[ci][cj] == true) {
				return false;
			}
		}

		// south - west
		for (int ci = i + 1, cj = j - 1; cj >= 0 && ci < board.length; cj--, ci++) {
			if (board[ci][cj] == true) {
				return false;
			}
		}

		// north - west
		for (int cj = j - 1, ci = i - 1; cj >= 0 && ci >= 0; cj--, ci--) {
			if (board[ci][cj] == true) {
				return false;
			}
		}
		return true;

	}

	// lqpinwb = last queen placed in what box
	public static void nqueen(boolean[][] board, int cb, int qpsf, String asf) {
		if (cb == board.length * board.length) {
			if (qpsf == board.length) {
				System.out.println(asf);
			}
			return;
		}
		nqueen(board, cb + 1, qpsf, asf);
		int i = cb / board.length;
		int j = cb % board.length;

		if (board[i][j] == false && isQueenSafe(board, i, j)) {
			board[i][j] = true;
			nqueen(board, cb + 1, qpsf + 1, asf + i + j + " ");
			board[i][j] = false;
		}
	}

}
