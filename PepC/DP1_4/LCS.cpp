#include<iostream>
#include<vector>
#include<string>

using namespace std;

// longest common subsequence

void lcsPath(vector<vector<int>>& strg, int i, int j, string& str1, string str2, string psf)
{  
    if(str1[i] == str2[i])
    {
        psf += str1[i];
    }

}

void lcs(string& str1, string& str2)
{
    vector<vector<int>> strg (str1.size() + 1, vector<int>(str2.size() + 1, 0));
    str1 += 'x';
    str2 += 'x';
    for(int i = strg.size() - 2; i >= 0; i--)
    {
        for(int j = strg[0].size() - 2; j >= 0; j--)
        {
            if(str1[i] == str2[j])
            {
                strg[i][j] = strg[i + 1][j + 1] + 1;
            }
            else
            {
                strg[i][j] = max(strg[i + 1][j], strg[i][j + 1]);
            }
            
        }
    }
    cout << strg[0][0] << endl;
    for(int i = 0; i < strg.size(); i++)
    {
        for(int j = 0; j < strg[0].size(); j++)
        {
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    lcsPath(strg, 0, 0, str1, str2, "");
}

int main(int argc, char** argv)
{
    string str1 = "abcd";
    string str2 = "aebd";
    lcs(str2, str1);
}