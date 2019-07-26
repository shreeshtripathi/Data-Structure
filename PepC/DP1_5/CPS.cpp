// Code- count palindromic subsequences
#include<iostream>
#include<vector>

using namespace std;

void countPalindromicSq(string& str)
{
    vector<vector<int>> strg(str.size(), vector<int>(str.size(), 0));

    for(int gap = 0; gap < str.size(); gap++)
    {
        for(int i = 0, j = i + gap; j < str.size(); i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = 1;
            }
            else if(gap == 1)
            {
                strg[i][j] = str[i] == str[j] ? 3 : 2;
            }
            else
            {
                if(str[i] == str[j])
                {
                    strg[i][j] = strg[i + 1][j] + strg[i][j - 1] + 1;
                }
                else
                {
                    strg[i][j] = strg[i + 1][j] + strg[i][j - 1] - strg[i + 1][j - 1];
                }
                
            }
            
        }
    }

    cout << strg[0][strg[0].size() - 1] << endl;
}

int main(int argc, char** argv)
{
    string str = "abgcckyb";
    countPalindromicSq(str);
}