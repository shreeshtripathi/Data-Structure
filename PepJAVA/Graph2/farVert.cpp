#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>
using namespace std;

class Edge
{
    public:
    int n;
    int wt;

    Edge(int n, int wt)
    {
        this->n = n;
        this->wt = wt;
    }
};

void addEdge(vector<vector<Edge>>& graph, int v1, int v2, int wt)
{
    graph[v1].push_back(Edge(v2, wt));
    graph[v2].push_back(Edge(v1, wt));
}

void display(vector<vector<Edge>>& graph)
{
    cout << "-----------------------------" << endl;
        for (int v = 0; v < graph.size(); v++) {
            cout << v  <<  "->";
            for (int n = 0; n < graph[v].size(); n++) {
                Edge ne = graph[v][n];
                cout << "[" << ne.n << "-" << ne.wt << "], ";
            }
            cout << endl;
        }
        cout << "-----------------------------" << endl;
}

class Qhelper
{
    public:
        string path;
        int fd;

        Qhelper(string path, int fd)
        {
            this->path = path;
            this->fd = fd;
        }

        bool operator<(const Qhelper& o)const
        {
            return this->fd < o.fd;
        }

        bool operator>(const Qhelper& o)const
        {
            return this->fd > o.fd;
        }
};

void farComp(vector<vector<Edge>>& graph, int src, int v, priority_queue<Qhelper>& pq)
{
    list<int> queue;
    vector<bool> visited(graph.size(), false);
    queue.push_back(src);

    Qhelper q("", 0);
    while(queue.size() > 0)
    {
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true)
        {
            continue;
        }
        else
        {
            visited[rem] = true;
        }
        q.path += to_string(rem);
        q.fd += 1;

        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            if(visited[ne.n] == false)
            {
                queue.push_back(ne.n);
            }
        }
    }
    pq.push(q);
}

void farVertMinPath(vector<vector<Edge>>& graph)
{
    
    priority_queue<Qhelper> pq;
    priority_queue<Qhelper, vector<Qhelper>, greater<Qhelper>> pd;

    for(int src = 0; src < graph.size(); src++)
    {
        for(int v = 0; v < graph.size(); v++)
        {
            farComp(graph, src, v, pq);
            pd.push(pq.top());
        }
    }

    Qhelper res = pd.top();
}

int main(int argc, char** argv)
{
    vector<vector<Edge>> graph(23);
    addEdge(graph, 0, 15, 0);
    addEdge(graph, 1, 15, 0);
    addEdge(graph, 15, 2, 0);
    addEdge(graph, 2, 3, 0);
    addEdge(graph, 2, 4, 0);
    addEdge(graph, 4, 5, 0);
    addEdge(graph, 4, 6, 0);
    addEdge(graph, 2, 7, 0);
    addEdge(graph, 7, 8, 0);
    addEdge(graph, 7, 9, 0);
    addEdge(graph, 8, 16, 0);
    addEdge(graph, 16, 17, 0);
    addEdge(graph, 16, 18, 0);
    addEdge(graph, 16, 19, 0);
    addEdge(graph, 19, 20, 0);
    addEdge(graph, 20, 21, 0);
    addEdge(graph, 20, 22, 0);
    addEdge(graph, 9, 10, 0);
    addEdge(graph, 10, 11, 0);
    addEdge(graph, 10, 12, 0);
    addEdge(graph, 12, 13, 0);
    addEdge(graph, 12, 14, 0);

    // display(graph);

    farVertMinPath(graph);
}