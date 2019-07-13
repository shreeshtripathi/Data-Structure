package Lecture18;

public class CrossWord1 {

	public static void main(String[] args) {
		char[][] board = { 
				{ '+', '+', '+', '+', '+', '+', '-', '+', '+', '+' },
				{ '+', '+', '-', '-', '-', '-', '-', '-', '+', '+' },
				{ '+', '+', '+', '+', '+', '+', '-', '+', '+', '+' },
				{ '+', '+', '+', '+', '+', '+', '-', '+', '+', '+' },
				{ '+', '+', '+', '-', '-', '-', '-', '-', '-', '+' },
				{ '+', '+', '+', '+', '+', '+', '-', '+', '-', '+' },
				{ '+', '+', '+', '+', '+', '+', '-', '+', '-', '+' },
				{ '+', '+', '+', '+', '+', '+', '+', '+', '-', '+' },
				{ '+', '+', '+', '+', '+', '+', '+', '+', '-', '+' },
				{ '+', '+', '+', '+', '+', '+', '+', '+', '-', '+' }
		};
		String[] words = { "ICELAND", "MEXICO", "PANAMA", "ALMATY" };
		crossWord1(board, words, 0);
	}

	public static boolean cpwh(char[][] board, int i, int j, String cw) {
		if(j + cw.length() > board.length) {
			return false;
		}
		if(j != 0 && board[i][j - 1] != '+') {
			return false;
		}
		if(j + cw.length() != board.length && board[i][j + cw.length()] != '+') {
			return false;
		}
		for(int c = 0; c < cw.length(); c++) {
			if(board[i][j + c] != '-' && board[i][j + c] != cw.charAt(c)) {
				return false;
			}
		}
		return true;
	}

	public static boolean cpwv(char[][] board, int i, int j, String cw) {
		if(i + cw.length() > board.length) {
			return false;
		}
		if(i != 0 && board[i - 1][j] != '+') {
			return false;
		}
		if(i + cw.length() != board.length && board[i + cw.length()][j] != '+') {
			return false;
		}
		for(int c = 0; c < cw.length(); c++) {
			if(board[i + c][j] != '-' && board[i + c][j] != cw.charAt(c)) {
				return false;
			}
		}
		return true;
	}

	public static void placeH(char[][] board, int i, int j, String cw, boolean dipit[]) {
		for(int c = 0; c < cw.length(); c++) {
			if(cw.charAt(c) == '-') {
				dipit[c] = true;
			}
			board[i][j + c] = cw.charAt(c);
		}
	}

	public static void unplaceH(char[][] board, int i, int j, String cw, boolean dipit[]) {
		for(int c = 0; c < cw.length(); c++) {
			if(dipit[c] == true) {
				board[i][j + c] = '-';
			}
		}
	}

	public static void placeV(char[][] board, int i, int j, String cw, boolean dipit[]) {
		for(int c = 0; c < cw.length(); c++) {
			if(cw.charAt(c) == '-') {
				dipit[c] = true;
			}
			board[i + c][j] = cw.charAt(c);
		}
	}

	public static void unplaceV(char[][] board, int i, int j, String cw, boolean dipit[]) {
		for(int c = 0; c < cw.length(); c++) {
			if(dipit[c] == true) {
				board[i + c][j] = '-';
			}
		}
	}

	public static void crossWord1(char[][] board, String[] words, int wpsf) {

		if (wpsf == words.length) {
			for (int i = 0; i < board.length; i++) {
				for (int j = 0; j < board.length; j++) {
					System.out.print(board[i][j] + " ");
				}
				System.out.println();
			}
			return;
		}

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length; j++) {
				if (board[i][j] == '-' || words[wpsf].charAt(0) == board[i][j]) {
					if (cpwh(board, i, j, words[wpsf])) {
						boolean dipit[] = new boolean[words[wpsf].length()];
						placeH(board, i, j, words[wpsf],dipit);
						crossWord1(board, words, wpsf + 1);
						unplaceH(board, i, j, words[wpsf],dipit);
					}
					if (cpwv(board, i, j, words[wpsf])) {
						boolean dipit[] = new boolean[words[wpsf].length()];
						placeV(board, i, j, words[wpsf], dipit);
						crossWord1(board, words, wpsf + 1);
						unplaceV(board, i, j, words[wpsf], dipit);
					}
				}
			}
		}
	}

}
