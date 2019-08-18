//Code- nCr style, problem is nQueens in which queens are at level

#include<iostream>
#include<vector>
using namespace std;

int count = 0;

void display(vector<vector<int>> &bd){
    for(int i = 0; i < bd.size(); i++){
        for(int j = 0; j < bd[0].size(); j++){
            cout << bd[i][j];
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

bool isSafe(vector<vector<int>> &bd, int i, int j){
    // north
    for(int ci = i - 1, cj = j; ci >= 0; ci--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south
		for(int ci = i + 1, cj = j; ci < bd.size(); ci++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// east
		for(int ci = i, cj = j + 1; cj < bd.size(); cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// west
		for(int ci = i, cj = j - 1; cj >= 0; cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// north - west
		for(int ci = i - 1, cj = j - 1; ci >= 0 && cj >= 0; ci--, cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// north - east
		for(int ci = i - 1, cj = j + 1; ci >= 0 && cj < bd.size(); ci--, cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south - east
		for(int ci = i + 1, cj = j + 1; ci < bd.size() && cj < bd.size(); ci++, cj++) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		// south - west
		for(int ci = i + 1, cj = j - 1; cj >= 0 && ci < bd.size(); ci++, cj--) {
			if(bd[ci][cj] != 0) {
				return false;
			}
		}
		return true;
}

void nq_npr(vector<vector<int>> &bd, int lqinwb, int cq){
    if(cq > bd.size()){
        display(bd);
        count++;
        return;
    }

    for(int b = lqinwb; b < bd.size() * bd.size(); b++){
        int i = b / bd.size();
        int j = b % bd.size();
        if(bd[i][j] == 0 && isSafe(bd, i, j)){
            bd[i][j] = cq;
            nq_npr(bd, b + 1, cq + 1);
            bd[i][j] = 0;
        }

    }
}

int main(){
    vector<vector<int>> bd {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    nq_npr(bd, 0, 1);
    cout << count << endl;
    return 0;
}