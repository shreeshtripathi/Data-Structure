#include<iostream>
#include<vector>
#include<string> 
    
using namespace std;

void lps(string& str)
{
    vector<vector<int>> strg(str.size(), vector<int>(str.size(), 0));
    
    for(int gap = 0; gap < strg.size(); gap++)
    {
        for(int i = 0, j = i + gap; j < strg.size(); i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = 1;
            }
            else if(gap == 1)
            {
                if(str[i] == str[j])
                {
                    strg[i][j] = 2;
                }
                else
                {
                    strg[i][j] = 1;
                }
            }
            else
            {
                if(str[i] == str[j])
                {
                    strg[i][j] = 2 + strg[i + 1][j - 1];
                }
                else
                {
                    strg[i][j] = max(strg[i][j - 1], strg[i + 1][j]);
                }
            }
        }
    }

    cout << strg[0][strg[0].size() - 1] << endl;
}

int main(int argc, char** argv)
{
    string str = "abkccgbc";
    lps(str);
}