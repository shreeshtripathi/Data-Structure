#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void ff(vector<vector<int>>& arr , int cr, int cc, int dr, int dc, string psf){
    if(cr == dr && cc == dc){
        cout << psf << endl;
        return;
    }
    if(cr < 0 || cc > dc || cc < 0 || cr > dr || arr[cr][cc] == 1 || arr[cr][cc] == 2){
        return;
    }
    arr[cr][cc] = 2; //visited
    ff(arr, cr - 1, cc, dr, dc, psf + "t");
    ff(arr, cr, cc - 1, dr, dc, psf + "l");
    ff(arr, cr + 1, cc, dr, dc, psf + "d");
    ff(arr, cr, cc + 1, dr, dc, psf + "r");
    arr[cr][cc] = 0;//unvisted
}

vector<string>* gff(vector<vector<int>> &arr, int cr, int cc, int dr, int dc){
    
    if(cr == dr || cc == dc){
        vector<string>* bres = new vector<string>;
        bres -> push_back("");
        return bres;
    }

    if(cr > dr || cr < 0 || cc > dc || cc < 0 || arr[cr][cc] == 1 || arr[cr][cc] == 2){
        vector<string>* fail = new vector<string>;
        return fail;
    }

    arr[cr][cc] = 2;
    vector<string>* left = gff(arr, cr, cc - 1, dr, dc);
    vector<string>* down = gff(arr, cr + 1, cc, dr, dc);
    vector<string>* right = gff(arr, cr, cc + 1, dr, dc);
    vector<string>* top = gff(arr, cr - 1, cc, dr, dc);
    arr[cr][cc] = 0;
    vector<string>* mres = new vector<string>;

    for(int i = 0; i < left->size(); i++){
        mres->push_back("L" + (*left)[i]);
    }
    for(int i = 0; i < down->size(); i++){
        mres->push_back("D" + (*down)[i]);
    }
    for(int i = 0; i < right->size(); i++){
        mres->push_back("R" + (*right)[i]);
    }
    for(int i = 0; i < top->size(); i++){
        mres->push_back("T" + (*top)[i]);
    }

    return mres;
}

int main(){
    vector<vector<int>> arr {
				{0, 1, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 1, 0, 0, 0, 0}
		};
    //ff(arr, 0, 0, arr.size() - 1, arr[0].size() - 1,"");
    vector<string>* ans = gff(arr, 0, 0, arr.size() - 1, arr[0].size() - 1);
    for(auto i = ans->begin(); i !=ans->end(); i++){
        cout << *i << " " << endl;
    }
    return 0;
}