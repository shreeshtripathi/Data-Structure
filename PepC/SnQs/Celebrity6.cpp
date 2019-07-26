#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int celebrity(vector<vector<int>>& vec)
{
    int left = 0;
    int right = vec.size() - 1;
    while(left < right)
    {
        if(vec[left][right] == 1)
        {
            left++; // discard left
        }
        else
        {
            right--; // discard right
        }
    }
    
    // confirmation
    for(int i = 0; i < vec.size(); i++)
    {
        if(i != left)
        {
            if(vec[i][left] == 0 || vec[left][i] == 1)
            {
                return -1;
            }
        }
    }

    return left;
}


int main(int argc, char** argv)
{
    vector<vector<int>> vec {
        {0, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 0},
    };

    cout << "celebrity is " << celebrity(vec) << endl;
}