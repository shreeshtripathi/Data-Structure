#include<iostream>
#include<vector>
#include<string>

using namespace std;

void populateZarray(vector<int>& zarray, string& str)
{
    int l = 0;
    int r = 0;
    int i = 1;
    while(i < zarray.size())
    {
        if(i > r)
        {
            l = r= i;
            while(r < zarray.size() && str[r] == str[r - l])
            {
                r++;
            }
            r--;
            zarray[l] = r - l + 1;
        }
        else
        {   
            int k = i - l;
            if(zarray[k] < r - i + 1)
            {
                zarray[i] = zarray[k];
            }
            else
            {
                r = i;
                while(r < zarray.size() && str[r] == str[r - l])
                {
                    r++;
                }
                r--;
                zarray[l] = r - l + 1;
            }
            
        }
        i++;
    }
}

void PatternMatching(string& src, string& pat)
{
    string cat = pat + "$" + src;
    vector<int> zarray(cat.size(), 0);
    populateZarray(zarray, cat);
    for(int i = 0; i < zarray.size(); i++)
    {
        if(zarray[i] == pat.size())
        {
            cout << i - pat.size() - 1 << ", ";
        }
    }
    cout << endl;
}

int main(int argv, char** argc)
{
    string src = "bacabbbcbabbcbabbcd";
    string pat = "abbc";
    PatternMatching(src, pat);
}
