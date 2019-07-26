#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int optimalBST(vector<int>& e, vector<int>& fq, vector<int>&ofq)
{
    vector<vector<int>> strg(e.size(), vector<int>(e.size(), 0));

    for(int gap = 0; gap < strg.size(); gap++)
    {
        for(int i = 0, j = i + gap; j < strg.size();i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = fq[i];
            }
            else if(gap == 1)
            {
                strg[i][j] = min(2 * strg[i][j - 1] + strg[i + 1][j], strg[i][j - 1] + 2 * strg[i + 1][j]);
            }
            else
            {
                int mymin = INT_MAX; // suppose it is infinity
                for(int k = -1; k < gap; k++)
                {
                    int lhs = k == -1 ? 0 : strg[i][j - gap + k];
                    int rhs = k == gap - 1 ? 0: strg[i + 2 + k][j];
                    int totalc = lhs + rhs + ofq[j];
                    if(i > 0)
                    {
                        totalc -= ofq[i-1];
                    }
                    mymin = min(mymin, totalc);
                }   
                strg[i][j] = mymin;               
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
    vector<int> element {5, 7, 8, 17, 20};
    vector<int> fq{4, 7, 5, 1, 2};
    vector<int> ofq(fq.size(), 0);
    int sum = fq[0];
    for(int i = 1; i < ofq.size(); i++)
    {
        sum = sum + fq[i];
        ofq[i] = sum;
    }

    optimalBST(element, fq, ofq);
}