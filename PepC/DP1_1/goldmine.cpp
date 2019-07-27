#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

vector<string> goldpsf;
int mymax = 99999; 

void goldMineSolver(vector<vector<int>>& mine)
{
    // fiish it
    vector<vector<int>> global(mine.size(), vector<int>(mine[0].size(), 0));

    for(int j = global[0].size()-1; j >= 0; j--)
    {
        for(int i = 0; i < global.size(); i++)
        {
            if(j == global[0].size() - 1)
            {
                global[i][j] = mine[i][j];
            }
            else if(i == 0)
            {
                global[i][j] = mine[i][j] + max(global[i][j + 1], global[i + 1][j + 1]);
            }
            else if(i == global.size() - 1)
            {
                global[i][j] = mine[i][j] + max(global[i][j + 1], global[i - 1][j + 1]);
            }
            else
            {
                global[i][j] =  mine[i][j] + max(global[i - 1][j + 1], max(global[i][j + 1], global[i + 1][j + 1]));
            }
        }
    }

    for(int i = 0; i < global.size(); i++)
    {
        for(int j = 0; j < global[0].size(); j++)
        {
            cout << global[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> mine {
        {1,5,1,0,3},
        {1,4,0,2,3},
        {4,0,1,3,2},
        {2,4,0,4,1},
        {1,2,3,2,0}
    };

    goldMineSolver(mine);
}