// nCr style, problem is n queens in which boxes are at level
#include<iostream>
#include<vector>
using namespace std;

int count = 0;

void display(vector<vector<int>> &bd){
    for(int i = 0; i < bd.size(); i++){
        for(int j = 0; j < bd[0].size(); j++){
            cout << bd[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-X-X-X-X-" << endl;
}

bool isSafe(vector<vector<int>> &bd, int i, int j){
    if(i - 2 >= 0 && j + 1 < bd.size() && bd[i - 2][j + 1] != 0){
		return false;
	} else if(i - 1 >= 0 && j + 2 < bd.size() && bd[i - 1][j + 2] != 0){
		return false;
	} else if(i + 1 < bd.size() && j + 2 < bd.size() && bd[i + 1][j + 2] != 0){
		return false;
	} else if(i + 2 < bd.size() && j + 1 < bd.size() && bd[i + 2][j + 1] != 0){
		return false;
	} else if(i + 2 < bd.size() && j - 1 >= 0 && bd[i + 2][j - 1] != 0){
		return false;
	} else if(i + 1 < bd.size() && j - 2 >= 0 && bd[i + 1][j - 2] != 0){
		return false;
	} else if(i - 1 >= 0 && j - 2 >= 0 && bd[i - 1][j - 2] != 0){
		return false;
	} else if(i - 2 >= 0 && j - 1 >= 0 && bd[i - 2][j - 1] != 0){
		return false;
	} else{
		return true;
	}
}

void nK_bnCr(vector<vector<int>> &bd, int b, int kpsf){
    if(b == bd.size() * bd.size()){
        if(kpsf == bd.size()){
        	count++;
            display(bd);
        }
        return;
    }


    nK_bnCr(bd, b + 1, kpsf);
    int i = b / bd.size();
    int j = b % bd.size();
    if(bd[i][j] == 0 && isSafe(bd, i, j)){
        bd[i][j] = kpsf + 1;
        nK_bnCr(bd, b + 1, kpsf + 1);
        bd[i][j] = 0;
    }
}

int main(){
    vector<vector<int>> bd {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    nK_bnCr(bd, 0, 0);
    cout << count << endl;
    return 0;
}
