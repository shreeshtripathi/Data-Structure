//code - lpss = longest palindromic sub string
//code - cpss = count palindromic sub string
#include<iostream>
#include<vector>

using namespace std;

void lpss_cpss(string& str)
{
    vector<vector<bool>> strg(str.size(), vector<bool>(str.size(), false));
    int len = 0;
    int count = 0;
    for(int gap = 0; gap < str.size(); gap++)
    {
        for(int i = 0, j = i + gap; j < str.size(); i++, j++)
        {
            if(gap == 0)
            {
                strg[i][j] = true;
            }
            else if(gap == 1)
            {
                strg[i][j] = str[i] == str[j];
            }
            else
            {
                if(str[i] == str[j])
                {
                    strg[i][j] = strg[i + 1][j - 1];
                }
                else
                {
                    strg[i][j] = false;
                }
                
            }
            if(strg[i][j])
            {
                count++;
                len = gap + 1;
            }
        }
    }

    cout << len << " " << count << endl;
}

int main(int argc, char** aargv)
{
    string str = "abccbc";
    lpss_cpss(str);
}