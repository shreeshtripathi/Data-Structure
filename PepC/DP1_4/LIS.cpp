#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

// longest increasing subsequence
void lisAllPath(vector<int>& v, vector<int>& strg, int i, string psf)
{
    if(i == 0)
    {
        cout << psf << endl;
        return;
    }
    for(int j = i - 1; j >= 0; j--)
    {
        if(strg[j] == strg[i] - 1 && strg[j] < strg[i])
        {
            lisAllPath(v, strg, j, psf + " " + to_string(v[j]));
        }
    }
}

void lis(vector<int>& v)
{
    vector<int> strg(v.size(), 0);

    int len = 0;
    for(int s = 0; s < v.size(); s++)
    {
        int mymax = 0;
        for(int i = 0; i <= s; i++)
        {
            if(v[i] <= v[s])
            {
                int num = strg[i] + 1;
                mymax = max(mymax, num);
            }
        }
        strg[s] = mymax;
        if(strg[s] > len)
        {
            len = strg[s];
        }
    }
    cout << len << endl;
    cout << "All paths are : " << endl;

    for(int i = 0; i < strg.size(); i++)
    {
        cout << strg[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < strg.size(); i++)
    {
        if(strg[i] == len)
        {
            lisAllPath(v,strg, i, "" + to_string(v[i]));
        }
    }
}

int main()
{
    vector<int> v {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    lis(v);
}