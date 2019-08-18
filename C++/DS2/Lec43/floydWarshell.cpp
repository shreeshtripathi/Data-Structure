#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void floydWarshell(vector<vector<int>>& graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        for(int s = 0; s < graph.size(); s++)
        {
            for(int d = 0; d < graph.size(); d++)
            {
                if( i == s || d == i || s == d)
                {
                    continue;
                }
                else if(graph[s][i] == INT_MAX || graph[i][d] == INT_MAX)
                {
                    continue;
                }
                else
                {
                    graph[s][d] = min(graph[s][d], graph[s][i] + graph[i][d]);
                }
                
            }
        }
    }

    // printing

    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph.size(); j++)
        {
            if(graph[i][j] == INT_MAX)
            {
                cout << "* "; 
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> graph{
        {INT_MAX, 2, 8, 10},
        {INT_MAX, INT_MAX, 3, 7},
        {INT_MAX, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX}
    };

    floydWarshell(graph);
}