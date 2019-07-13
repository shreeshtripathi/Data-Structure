package Recursion_imp;

import java.util.*;

public class crossWord_si {

	public static class Slot{
		int row;
		int col;
		int len;
		boolean isV;
		Slot(int row, int col, int len, boolean isV){
			this.row = row;
			this.col = col;
			this.len = len;
			this.isV = isV;
		}
	};
	
	static char[][] board = {
			{'+','+','+','+','+'},
			{'-','-','-','+','+'},
			{'-','+','+','-','+'},
			{'-','+','+','-','+'},
			{'+','+','+','-','+'}
	};

	static int counter = 0;	
	public void display(char[][] board) {
		System.out.println("--------" + counter + "--------");
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board.length; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
		System.out.println("--------" + counter + "--------");
	}
	
	static ArrayList<Slot> slots = new ArrayList<>();
	private static void setslots(char[][] baord) {
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board.length; j++) {
				
				if(board[i][j] == '-' ) {
					// check for horizontal availability
					if(j == 0 || board[i][j - 1] == '+'){
						int len = 0;
						while(j + len < board.length && board[i][j + len] == '-'){
							len++;
						}
						
						if(len > 1){
							slots.add(new Slot(i, j, len, false));
						}
					}
					// check for vertical availability
					if(i == 0 || board[i - 1][j] == '+'){
						int len = 0;
						while(i + len < board.length && board[i + len][j] == '-'){
							len++;
						}
						
						if(len > 1){
							slots.add(new Slot(i, j, len, false));
						}
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		String[] word = {"and", "ant", "too"};
	}

}
