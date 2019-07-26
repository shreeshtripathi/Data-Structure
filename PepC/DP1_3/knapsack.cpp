#include<iostream>
#include<vector>

using namespace std;

void knapsackUnbound(vector<int>& wts, vector<int>& price, int cap)
{
    vector<int> strg(cap + 1, 0);

    for(int s = 1; s <= cap; s++)
    {
        for(int i = 0; i < wts.size(); i++)
        {
            if(s >= wts[i])
            {
                strg[s] = max(strg[s - wts[i]] + price[i], strg[s]);
            }
        }
    }

    for(int i = 0; i < strg.size(); i++)
    {
        cout << strg[i] << " ";
    }
    cout << endl;
}

void knapsack1_0(vector<int>& wts, vector<int>& price, int cap)
{
    vector<vector<int>> strg(wts.size() + 1, vector<int>(cap + 1, 0));

    for(int i = 0; i < strg.size(); i++)
    {
        for(int j = 0; j < strg[0].size(); j++)
        {
            if(i == 0 && j == 0)
            {
                strg[i][j] = 0;
            } 
            else if(i == 0)
            {
                strg[i][j] = 0;
            } 
            else if(j == 0)
            {
                strg[i][j] = 0;
            }
            else
            {
                // if dont't bat
                strg[i][j] = strg[i - 1][j];
                
                // now check for max of yes bat and no bat
                if(j >= wts[i - 1] && strg[i][j] < (price[i - 1] + strg[i - 1][j - wts[i - 1]]))
                strg[i][j] = price[i - 1] + strg[i - 1][j - wts[i - 1]];
            }
        }
    }

    for(int i = 0; i < strg.size(); i++)
    {
        for(int j = 0; j < strg[0].size(); j++)
        {
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char** argv)
{
    vector<int> wts {2, 5, 1, 3, 4};
    vector<int> price {15, 14, 10, 45, 30};
    int cap = 7;
    knapsack1_0(wts, price, cap);

    cout << "~~~~~~~~~~~~~~~~~~" << endl;
    knapsackUnbound(wts, price, cap);
}