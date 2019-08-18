#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <climits>

using namespace std;

class Edge
{
public:
    int o;
    int n;
    int wt;
    Edge(int o, int n, int wt)
    {
        this->n = n;
        this->o = o;
        this->wt = wt;
    }
};

void addEdge(vector<vector<Edge *>> &graph, int v1, int v2, int wt)
{
    graph[v1].push_back(new Edge(v1, v2, wt));
    graph[v2].push_back(new Edge(v2, v1, wt));
}

void display(vector<vector<Edge *>> &graph)
{
    for (int v = 0; v < graph.size(); v++)
    {
        cout << v << " -> ";
        for (int e = 0; e < graph[v].size(); e++)
        {
            Edge *edge = graph[v][e];
            cout << "[" << edge->o << " " << edge->n << " " << edge->wt << "]"
                 << ",";
        }
        cout << endl;
    }
}

bool hasPath(vector<vector<Edge *>> &graph, int src, int dest, vector<bool> visited)
{

    if (src == dest)
    {
        return true;
    }

    visited[src] = true;
    for (int e = 0; e < graph[src].size(); e++)
    {
        Edge *edge = graph[src][e];
        if (visited[edge->n] == false)
        {
            bool pfn = hasPath(graph, edge->n, dest, visited);
            if (pfn == true)
            {
                return true;
            }
        }
    }

    return false;
}
void printAllPath(vector<vector<Edge *>> &graph, int src, int dest,
                  vector<bool> visited, string psf, int dsf)
{
    if (src == dest)
    {
        cout << psf << " " << src << " @ " << dsf << endl;
        return;
    }

    visited[src] = true;
    for (int e = 0; e < graph[src].size(); e++)
    {
        Edge *edge = graph[src][e];
        if (visited[edge->n] == false)
        {
            printAllPath(graph, edge->n, dest, visited, psf + " " + to_string(src), dsf + edge->wt);
        }
    }
    visited[src] = false;
}

int main(int argv, char **argc)
{
    int n = 7;
    vector<vector<Edge *>> graph(n);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    addEdge(graph, 2, 5, 5);
    // display(graph);
    cout << "----------------" << endl;
    vector<bool> visited(n, false);
    //cout << hasPath(graph, 0, 7, visited) << endl;
    printAllPath(graph, 0, 6, visited, "", 0);
    cout << "----------------" << endl;
}