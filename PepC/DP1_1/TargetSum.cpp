#include<iostream>
#include<string>
#include<vector>

using namespace std;

void pts(vector<vector<bool>>& strg, int i, int j, vector<int>& arr, string psf)
{
    if(j == 0)
    {
        cout << psf << endl;
        return;
    }
    else if(i == 0)
    {
        return;
    }
    else
    {
        // make two calls from here
        if(strg[i - 1][j] == true)
        {
            pts(strg, i - 1, j, arr, psf);
        }

        if(j >= arr[i - 1] && strg[i - 1][j - arr[i - 1]] == true)
        {
            pts(strg, i - 1, j - arr[i - 1], arr, psf +" " + to_string(arr[i - 1]));
        }
    }
    
}

bool Target(vector<int>& arr, int target)
{
    vector<vector<bool>> strg(arr.size() + 1, vector<bool>(target + 1, false));
    for(int i = 0; i < strg.size(); i++)
    {
        for(int j = 0; j < strg[0].size(); j++)
        {
            if(i == 0 && j == 0)
            {
                strg[i][j] = true;   
            }
            else if(j == 0)
            {
                strg[i][j] = true;
            }
            else if(i == 0)
            {
                strg[i][j] = false;
            }
            else
            {
                if(strg[i - 1][j] == true)
                {
                    strg[i][j] = true;
                }
                else if(j >= arr[i - 1] && strg[i - 1][j - arr[i - 1]] == true)
                {
                    strg[i][j] = true;
                }
            }
        }
    }

    pts(strg, strg.size() - 1, strg[0].size() -1, arr, "");

    return strg[strg.size() - 1][strg[0].size() - 1];
    
}

int main(int argc, char** argv)
{
    vector<int> arr{2, 5, 3, 1, 6};
    int target = 9;
    if(Target(arr, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}