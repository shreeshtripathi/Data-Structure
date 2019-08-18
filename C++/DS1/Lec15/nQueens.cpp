// Code- Reactive code for nQueens
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isQueenSafe(vector<vector<bool>> & box, int i, int j){
    // north
    for(int ii = i - 1, jj = j; ii >= 0; ii--){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // south
    for(int ii = i + 1, jj = j; ii < box.size(); ii++){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // east
    for(int ii = i, jj = j + 1; jj < box.size(); jj++){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // west
    for(int ii = i, jj = j - 1; jj >= 0; jj--){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // north-east
    for(int ii = i - 1, jj = j + 1; ii >= 0 && jj < box.size(); ii--, jj++){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // south-east
    for(int ii = i + 1, jj = j + 1; ii < box.size() && jj < box.size(); ii++, jj++){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // south-west
    for(int ii = i + 1, jj = j - 1; ii < box.size() && jj >= 0; ii++, jj--){
        if(box[ii][jj] == true){
            return false;
        }
    }
    // north-west
    for(int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--){
        if(box[ii][jj] == true){
            return false;
        }
    }
    return true;
}

bool isBoxSafe(vector<vector<bool>>& box){
    for(int i = 0; i < box.size(); i++){
        for(int j = 0; j < box.size(); j++){
            if(box[i][j] == true){
                if(isQueenSafe(box, i, j) == false){
                    return false;
                }
            }
        }
    }
    return true;

}

void nQueens(vector<vector<bool>> & box, int qpsf, int lqinwb, string asf){
    if(qpsf == box.size()){
        if(isBoxSafe(box) == true){
            cout << asf << endl; 
        }
        return;
    }
    //Trick - conversion of 1D array into 2D and  2D array into 1D makes traversal easier
    for(int cb = lqinwb + 1; cb < (box.size() * box.size()); cb++){
        int i = cb / box.size();
        int j = cb % box.size();
        if(box[i][j] == false){
            box[i][j] = true;
            nQueens(box, qpsf + 1, cb, asf + to_string(i) + to_string(j) + " ");
            box[i][j] = false;
        }
    }

}

int main(){
    vector<vector<bool>> box {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    nQueens(box, 0, -1,  "");
    return 0;
}