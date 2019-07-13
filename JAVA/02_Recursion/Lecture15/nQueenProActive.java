package Lecture15;

// Reactive
public class nQueenProActive {
	public static void main(String[] args) {
		boolean[][] board = new boolean[4][4];
		nqueen(board, -1, 0, "");

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
			if (board[i][cj] == true) {
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
	public static void nqueen(boolean[][] board, int lqpinwb, int qpsf, String asf) {
		if (qpsf == board.length) {
			System.out.println(asf);
			return;
		}

		for (int box = lqpinwb + 1; box < board.length * board.length; box++) {
			// Formula to conversion between 1D to 2D

			int cr = box / board.length;
			int cc = box % board.length;

			if (board[cr][cc] == false && isQueenSafe(board, cr, cc) == true) {
				board[cr][cc] = true;
				nqueen(board, box, qpsf + 1, asf + cr + cc + " ");
				board[cr][cc] = false;
			}
		}

	}

}
