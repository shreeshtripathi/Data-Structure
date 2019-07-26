//Code - minimum palindromic cut

// important looping concept :::::::::
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void mpc(string& str)
{
    vector<vector<int>> strg(str.size(), vector<int>(str.size(), 0));
    
    for(int gap = 0; gap < strg.size(); gap++)
    {
        for(int i = 0, j = i + gap; j < strg.size(); i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = 0;
            }
            else if(gap == 1)
            {
                strg[i][j] = str[i] == str[j] ? 0 : 1;
            }
            else
            {
                if(str[i] == str[j] && strg[i + 1][j - 1] == 0)
                {
                    strg[i][j] = 0;
                }
                else
                {
                    int mincut = str.size();
                    for(int k = 0; k < gap; k++)
                    {
                        int lhs = strg[i][j - gap + k];
                        int rhs = strg[i + 1 + k][j];
                        mincut = min(mincut, lhs + rhs);
                    }
                    strg[i][j] = mincut + 1;
                }
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
    
    cout << strg[0][strg[0].size() - 1] << endl;
}


int main(int argc, char** argv)
{
    string str = "abccbc";
    mpc(str);
}