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
/* Date : 11th April 2019*/

int spd = INT_MAX;
string sp = "";
int lpd = INT_MIN;
string lp = "";
void minmaxPath(vector<vector<Edge *>> &graph, int src, int dest, vector<bool> visited,
                string psf, int dsf)
{

    if (src == dest)
    {
        if (spd > dsf)
        {
            spd = dsf;
            sp = psf;
        }
        if (lpd < dsf)
        {
            lpd = dsf;
            lp = psf;
        }
        return;
    }

    visited[src] = true;
    for (int e = 0; e < graph[src].size(); e++)
    {
        Edge *edge = graph[src][e];
        if (visited[edge->n] == false)
        {
            minmaxPath(graph, edge->n, dest, visited, psf + " " + to_string(src), edge->wt + dsf);
        }
    }
    visited[src] = false;
}

int cpd = INT_MAX;
string cp = "";
int fpd = INT_MIN;
string fp = "";

void ceilfloorPath(vector<vector<Edge *>> &graph, int src, int dest, int factor, vector<bool> visited,
                   string psf, int dsf)
{
    if (src == dest)
    {
        if (dsf > factor && cpd > dsf)
        {
            cpd = dsf;
            cp = psf;
        }
        if (dsf < factor && dsf > fpd)
        {
            fpd = dsf;
            fp = psf;
        }

        return;
    }

    visited[src] = true;
    for (int e = 0; e < graph[src].size(); e++)
    {
        Edge *edge = graph[src][e];
        if (visited[edge->n] == false)
        {
            ceilfloorPath(graph, edge->n, dest, factor, visited, psf + " " + to_string(src), dsf + edge->wt);
        }
    }
    visited[src] = false;
}

void kthLargest(vector<vector<Edge *>> &graph, int src, int dest, int k)
{

    int factor = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        fp = "";
        fpd = INT_MIN;
        vector<bool> visited(graph.size(), false);
        ceilfloorPath(graph, src, dest, factor, visited, "", 0);
        // for next iteration we have to make factor as floor path dst of prevois iteration
        factor = fpd;
    }
    cout << fp << " @ " << fpd << endl;
}

void hamiltonian(vector<vector<Edge *>> &graph, int src, int os, vector<bool> visited, vector<int> psf)
{

    if (psf.size() == graph.size() - 1)
    {
        psf.push_back(src);
        for (int i = 0; i < psf.size(); i++)
        {
            cout << psf[i] << " ";
        }
        bool cycleDetected = false;
        for (int e = 0; e < graph[src].size(); e++)
        {
            Edge *edge = graph[src][e];
            if (edge->n == os)
            {
                cycleDetected = true;
                break;
            }
        }
        if (cycleDetected == true)
        {
            cout << "*" << endl;
        }
        else
        {
            cout << "." << endl;
        }

        psf.pop_back();
        return;
    }

    visited[src] = true;
    psf.push_back(src);
    for (int e = 0; e < graph[src].size(); e++)
    {
        Edge *edge = graph[src][e];
        if (visited[edge->n] == false)
        {
            hamiltonian(graph, edge->n, os, visited, psf);
        }
    }

    psf.pop_back();
    visited[src] = false;
}

void knightTour(vector<vector<Edge *>> &graph)
{
}

class THelper
{
public:
    int vtx;
    string psf;
    int dsf;
    THelper(int vtx, string psf, int dsf)
    {
        this->vtx = vtx;
        this->dsf = dsf;
        this->psf = psf;
    }
};

bool bfs(vector<vector<Edge *>> &graph, int src, int dest)
{
    list<THelper *> queue;
    THelper *t = new THelper(src, to_string(src), 0);
    queue.push_back(t);
    bool visited[graph.size()] = {false};
    while (queue.size() > 0)
    {
        //Get
        THelper *cp = queue.front();
        // Remove
        queue.pop_front();

        // Mark* - multiple marking
        if (visited[cp->vtx] == true)
        {
            continue;
        }
        else
        {
            visited[cp->vtx] = true;
        }
        // Work
        if (cp->vtx == dest)
        {
            cout << cp->psf << " @ " << cp->dsf << endl;
            return true;
        }
        // Add*
        for (int e = 0; e < graph[cp->vtx].size(); e++)
        {
            Edge *edge = graph[cp->vtx][e];
            int dist = edge->wt;
            if (visited[edge->n] == false)
            {
                THelper *np = new THelper(edge->n, cp->psf + to_string(edge->n), cp->dsf + dist);
                queue.push_back(np);
            }
        }
    }
    return false;
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
    minmaxPath(graph, 0, 6, visited, "", 0);
    cout << sp << " @ " << spd << endl;
    cout << lp << " @ " << lpd << endl;
    cout << "----------------" << endl;
    ceilfloorPath(graph, 0, 6, 52, visited, "", 0);
    cout << cp << " @ " << cpd << endl;
    cout << fp << " @ " << fpd << endl;
    cout << "----------------" << endl;
    kthLargest(graph, 0, 6, 5);
    cout << "----------------" << endl;
    vector<int> psf;
    hamiltonian(graph, 1, 1, visited, psf);
    bfs(graph, 0, 6);
}