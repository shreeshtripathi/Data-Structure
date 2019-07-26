// code - matrix chaining multiplication

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void minChainMultiplictaion(vector<int>& mat)
{
    vector<vector<int>> strg(mat.size() - 1, vector<int>(mat.size() - 1, 0));

    for(int gap = 0; gap < strg.size(); gap++)
    {
        for(int i = 0, j = gap + i; j < strg.size(); i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = 0;
            }
            else if(gap == 1)
            {
                strg[i][j] = mat[j - 1] * mat[j] * mat[j + 1];
            }
            else
            {
                int minCost = INT_MAX;
                for(int k = 0; k < gap; k++)
                {
                    int lhs = strg[i][j - gap + k];
                    int rhs = strg[i + 1 + k][j];
                    int mcost = mat[i] * mat[i + 1 + k] * mat[j + 1];  // it is from above line
                    int totalCost = lhs + rhs + mcost;
                    minCost = min(minCost, totalCost);
                    // strg[i][j] = strg[i][j] == 0? totalCost: min(totalCost, strg[i][j]);
                }
                strg[i][j] = minCost;
            }
        }
    }

    cout << strg[0][strg[0].size() - 1] << endl;
}

int main(int argc, char** argv)
{
    vector<int> mat{10, 20, 30, 40, 50, 60};

    minChainMultiplictaion(mat);
}