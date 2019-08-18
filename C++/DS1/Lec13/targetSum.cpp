#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>* tarSum(int arr[], int tar, int sp, int n){

    if(sp == n){
        vector<vector<int>>* bres = new vector<vector<int>>();
        if(tar == 0){
            vector<int> vk;
            bres->push_back(vk);
        }
        return bres;
    }

    vector<vector<int>>* rres1 = tarSum(arr, tar - arr[sp], sp + 1, n);
    vector<vector<int>>* rres2 = tarSum(arr, tar, sp + 1, n);
    vector<vector<int>>* mres = new vector<vector<int>>();
    for(int i = 0; i < rres1 -> size() ; i++){
        (*rres1)[i].push_back(arr[sp]);
        (*mres).push_back((*rres1)[i]);
    }
    for(int i = 0; i < rres2 -> size() ; i++){
        (*mres).push_back((*rres2)[i]);
    }

    return mres;

}


int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    vector<vector<int>> * ans = tarSum(arr,70, 0, 7);
    //sp = starting point

    for(int i = 0; i < ans -> size(); i++){
        for(int j = 0; j < (*ans)[i].size(); j++){
            cout << (*ans)[i][j] << " " ;
         }
         cout << endl;
    }
    return 0;

}