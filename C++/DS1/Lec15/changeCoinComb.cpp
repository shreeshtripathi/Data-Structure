//Change coin permutation
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void ccPermute(vector<int>& coins,int li, int amt, vector<int>& res){
    // cout << "Hello" << endl;
    if(amt == 0){
        
        if(res.size() == 10){
            for(int i = 0; i < res.size(); i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for(int i = li; i < coins.size(); i++){
        if(amt >= coins[i]){
            res.push_back(coins[i]);
            ccPermute(coins, i, amt - coins[i], res);
            res.pop_back();
        }
    }
}

int main(){
    vector<int> coins {1, 2, 5,20, 50};
    vector<int> res;
    ccPermute(coins, 0, 100, res);
    return 0;
}