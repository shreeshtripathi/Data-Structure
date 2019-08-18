// nPr style, problem is nQueens in which boxes are at level

#include<iostream>
#include<vector>
using namespace std;
int count = 0;

void display(vector<vector<int>> &bd){
    for(int i = 0; i < bd.size(); i ++){
        for(int j = 0; j < bd.size(); j++){
            cout << bd[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--x--x--x--" << endl;
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

void nprb(vector<vector<int>> &bd, int b, bool qu[], int qpsf){
    if(b == bd.size() * bd.size()){
        if(qpsf == bd.size()){
            display(bd);
            count++;
        }
        return;
    }



    nprb(bd, b + 1, qu, qpsf);
    for(int q = 0; q < bd.size(); q++){
        int i = b / bd.size();
        int j = b % bd.size();
        if(qu[q] == false && isSafe(bd, i, j)){
            bd[i][j] = q + 1;
            qu[q] = true;
            nprb(bd, b + 1, qu, qpsf + 1);
            qu[q] = false;
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
    // suppose we have 4 queens 
    bool qu[] = {0, 0, 0, 0};
    nprb(bd, 0, qu, 0);
    cout << count << endl;
    return 0;
}