#include<iostream>
#include<vector>

using namespace std;

// int minCostTravel(vector<vector<int>>& maze){
//     vector<vector<int>> strg(maze.size(), vector<int>(maze[0].size(), 0));
//     strg[0][0] = maze[0][0];
//     for(int i = 1; i < maze.size(); i++){
//         strg[0][i] = maze[0][i] + strg[0][i-1];
//     }

//     for(int j = 1; j < maze.size(); j++){
//         strg[j][0] = maze[j][0] + strg[j - 1][0];
//     }

//     for(int i = 1; i < maze.size(); i++){
//         for(int j = 1; j < maze[0].size(); j++){
//             strg[i][j] = min(strg[i][j - 1], strg[i - 1][j]) + maze[i][j];
//         }
//     }

//     cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//     for(int i = 0; i < maze.size(); i++){
//         for(int j = 0; j < maze[0].size(); j++){
//             cout << strg[i][j] << " ";
//         }
//         cout << endl;
//     }
    
//     cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//     return strg[strg.size() - 1][strg[0].size() - 1];
// }

void printMPC(vector<vector<int>>& strg, int r, int c, string psf)
{
    if(r == strg.size() - 1 && c == strg[0].size()){
        cout << psf << endl;
        return;
    }
    else if(r == strg.size() - 1)
    {
        printMPC(strg, r, c + 1, psf + "h");
    }
    else if(c == strg[0].size() - 1)
    {
        printMPC(strg, r + 1, c, psf + "v");
    }
    else
    {
        if(strg[r][c + 1] > strg[r + 1][c])
        {
            printMPC(strg, r + 1, c, psf + "v");
        }

        if(strg[r][c + 1] < strg[r + 1][c])
        {
            printMPC(strg, r, c + 1, psf + "h");
        }

        if(strg[r][c + 1] == strg[r + 1][c])
        {
            printMPC(strg, r + 1, c, psf + "v");
            printMPC(strg, r, c + 1, psf + "h");
        }

    }
    
}


int minCost(vector<vector<int>>& costs)
{
    vector<vector<int>> strg(costs.size(), vector<int>(costs[0].size(), 0));

    for(int i = costs.size() - 1; i >= 0; i--)
    {
        for(int j = costs[0].size() - 1; j >= 0; j--)
        {
            if(i == costs.size() -1 && j == costs[0].size() - 1){
                strg[i][j] = costs[i][j];
            }
            else if(i == costs.size() - 1)
            {
                strg[i][j] = costs[i][j] + strg[i][j + 1];
            }
            else if(j == costs[0].size() - 1)
            {
                strg[i][j] = costs[i][j] + strg[i + 1][j];
            }
            else
            {
                strg[i][j] = costs[i][j] + min(strg[i][j + 1], strg[i + 1][j]);
            }
        }
    }
    printMPC(strg, 0, 0, "");
    return strg[0][0];
}

int main(int argc, char** argv)
{
    vector<vector<int>> maze {
        {2, 6, 5, 1, 3, 4},
        {0, 4, 9, 2, 9, 0},
        {4, 8, 1, 0, 6, 5},
        {3, 3, 3, 1, 5, 4},
        {1, 2, 7, 0, 6, 9},
        {5, 7, 1, 3, 8, 2}
    };
    // cout << minCost(maze) << endl;

    cout << minCost(maze) << endl;
}