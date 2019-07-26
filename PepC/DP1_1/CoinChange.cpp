#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printCoinPer()
{
    
}

int coinPermutations(vector<int>& coins, int amt)
{
    vector<int> strg(amt + 1, 0);
    strg[0] = 1;
    for(int s = 1; s < strg.size(); s++)
    {
        for(int c = 0; c < coins.size(); c++)
        {
            int i = s - coins[c];
            if(i >= 0)
            {
                strg[s] += strg[i];
            }
        }
    }

    return strg[strg.size() - 1];
}

int coinCombinations(vector<int>& coins, int amt)
{
    vector<int> strg(amt + 1, 0);
    strg[0] = 1;

    for(int c = 0; c < coins.size(); c++)
    {
        for(int s = 1; s < strg.size(); s++)
        {
            int i = s - coins[c];
            if(i >= 0)
            {
                strg[s] += strg[i];
            }
        }
    }

    return strg[strg.size() - 1];
}

int main(int argc, char** argv)
{
    vector<int> coins{2, 3, 5, 6};
    int amt = 7;
    cout << coinPermutations(coins, amt) << endl;
    cout << coinCombinations(coins, amt) << endl;
}