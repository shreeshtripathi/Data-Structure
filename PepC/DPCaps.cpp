#include<iostream>
#include<vector>

using namespace std;

int CountWaysForParty_Rec(vector<vector<int>>& caps, int cper, vector<bool>& visited)
{
    if(cper == caps.size())
    {
        return 1;
    }
    int count = 0;
    
    for(int cap : caps[cper])
    {
        if(visited[cap] == false)
        {
            visited[cap] = true;
            count += CountWaysForParty_Rec(caps, cper + 1, visited);
            visited[cap] = false;
        }
    }
    return count;
}

int CountWaysForParty_DP_Bit(vector<vector<int>>& caps, int cper, int bmask, vector<vector<int>>& strg)
{
    if(cper == caps.size())
    {
        return 1;
    }
    if(strg[cper][bmask] != 0)
    {
        return strg[cper][bmask];
    }

    int count = 0;
    for(int cap : caps[cper])
    {
        if((bmask & (1 << cap)) == 0)
        {
            bmask = (bmask ^ (1 << cap));
            count += CountWaysForParty_DP_Bit(caps, cper + 1, bmask, strg);
            bmask = (bmask ^ (1 << cap));
        }
    }
    strg[cper][bmask] = count;
    return count;
}

int main(int argc, char** argv)
{
    // four persons -> p0, p1, p2, p3
    // five caps -> c0, c1, c2, c3, c4
    
    // DATA==> availability of caps on individual person have
    // p0 - c0, c2, c4
    // p1 - c0, c1, c2, c3
    // p2 - c1, c2, c3
    // p3 - c0, c4
    
    // find in how many different ways the person can go to the party so that no two person have same caps 
    vector<vector<int>> caps = {
        {0, 2, 4},
        {0, 1, 2, 3},
        {1, 2, 3},
        {0, 4}
    };

    // both above and below are working same
    // caps.push_back(vector<int>{0, 2, 4});
    // caps.push_back(vector<int>{0, 1, 2, 3});
    // caps.push_back(vector<int>{1, 2, 3});
    // caps.push_back(vector<int>{0, 4});

    // from recursion
    // vector<bool> visited(5, false);
    // cout << CountWaysForParty_Rec(caps, 0, visited) << endl;

    // from bitmasking and DP
    int bmask = 0;
    vector<vector<int>> strg(caps.size(), vector<int>(1 << 5, 0));
    cout << CountWaysForParty_DP_Bit(caps, 0, bmask, strg) << endl;
}