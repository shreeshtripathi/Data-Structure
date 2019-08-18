#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool cpwh(vector<vector<char>> board, int i, int j, string cw) {
		
}

bool cpwv(vector<vector<char>> board, int i, int j, string cw) {

}

void placeH(vector<vector<char>> board, vector<string> words, string cw) {

}

void unplaceH(vector<vector<char>> board, vector<string> words, string cw) {

}

void placeV(vector<vector<char>> board, vector<string> words, string cw) {

}

void unplaceV(vector<vector<char>> board, vector<string> words, string cw) {

}




void crossWord(vector<vector<char>> board, vector<string> words, int wpsf){
    if (wpsf == words.size) {
			for (int i = 0; i < board.size; i++) {
				for (int j = 0; j < board.size; j++) {
					cout << board[i][j] << " " << endl;
				}
				cout << endl;
			}
			return;
		}

		for (int i = 0; i < board.size; i++) {
			for (int j = 0; j < board.size; j++) {
				if (board[i][j] == '-' || words[wpsf][0] == board[i][j]) {
					if (cpwh(board, i, j, words[wpsf])) {
						placeH(board, words, words[wpsf]);
						crossWord(board, words, wpsf + 1);
						unplaceH(board, words, words[wpsf]);
					}
					if (cpwv(board, i, j, words[wpsf])) {
						placeV(board, words, words[wpsf]);
						crossWord(board, words, wpsf + 1);
						unplaceV(board, words, words[wpsf]);
					}
				}
			}
		}
}

int main(){
    vector<vector<char>> board { 
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
    vector<string> words = { "ICELAND", "MEXICO", "PANAMA", "ALMATY" };
    crossWord(board, words, 0);
    return 0;
}