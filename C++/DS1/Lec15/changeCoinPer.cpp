//Change coin permutation
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void ccPermute(vector<int>& coins, int amt, string asf){
    if(amt == 0){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < coins.size(); i++){
        if(amt >= coins[i]){
            ccPermute(coins, amt - coins[i], asf + to_string(coins[i]) + " ");
        }
    }
}

int main(){
    vector<int> coins {2, 3, 5};
    ccPermute(coins, 7, "");
    return 0;
}