#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <climits>
#include <queue>

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

    // for dijkstras algorithm we have to overload < operator
    bool operator<(const THelper &other) const
    {
        return this->dsf < other.dsf;
    }
    bool operator>(const THelper &other) const
    {
        return this->dsf > other.dsf;
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

/* Date : 12th April 2019*/

bool dfsi(vector<vector<Edge *>> &graph, int src, int dest)
{
    list<THelper *> stack;
    THelper *t = new THelper(src, to_string(src), 0);
    stack.push_front(t);
    bool visited[graph.size()] = {false};
    while (stack.size() > 0)
    {
        //Get
        THelper *cp = stack.front();
        // Remove
        stack.pop_front();

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
                stack.push_front(np);
            }
        }
    }
    return false;
}

void bfsLineWise(vector<vector<Edge *>> &graph, int src)
{
}

void gccComponents(vector<vector<Edge *>> &graph, int src, vector<int> &comp, vector<bool> &visited)
{
    list<THelper *> queue;
    THelper *t = new THelper(src, to_string(src), 0);
    queue.push_back(t);
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
        comp.push_back(cp->vtx);
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
}

void gcc(vector<vector<Edge *>> &graph, vector<vector<int>> &comp)
{
    vector<bool> visited(graph.size(), false);
    for (int v = 0; v < graph.size(); v++)
    {
        if (visited[v] == false)
        {
            vector<int> scomp;
            gccComponents(graph, v, scomp, visited);
            comp.push_back(scomp);
        }
    }
}

bool isConnected(vector<vector<Edge *>> &graph)
{
    vector<bool> visited(graph.size(), false);
    vector<int> comp;
    gccComponents(graph, 0, comp, visited);
    return comp.size() == graph.size();
}

bool isCyclicComp(vector<vector<Edge *>> &graph, int src, vector<bool> &visited)
{
    list<THelper *> queue;
    THelper *t = new THelper(src, to_string(src), 0);
    queue.push_back(t);
    while (queue.size() > 0)
    {
        //Get
        THelper *cp = queue.front();
        // Remove
        queue.pop_front();

        // Mark* - multiple marking
        if (visited[cp->vtx] == true)
        {
            return true;
        }
        else
        {
            visited[cp->vtx] = true;
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

bool isCyclic(vector<vector<Edge *>> &graph)
{
    vector<bool> visited(graph.size(), false);
    for (int v = 0; v < graph.size(); v++)
    {
        if (visited[v] == false)
        {
            bool isTrue = isCyclicComp(graph, v, visited);
            if (isTrue == true)
            {
                return true;
            }
        }
    }
    return false;
}

bool isTree(vector<vector<Edge *>> &graph)
{
    return !isCyclic(graph) && isConnected(graph);
}

bool isBipertiteComp(vector<vector<Edge *>> &graph, int src, vector<int> &visited)
{
    list<THelper *> queue;
    THelper *t = new THelper(src, to_string(src), 0);
    int level = 1;
    queue.push_back(t);
    queue.push_back(NULL);
    while (queue.size() > 0)
    {
        //Get
        THelper *cp = queue.front();
        // Remove
        queue.pop_front();
        if (cp == NULL)
        {
            if (queue.size() > 0)
            {
                queue.push_back(NULL);
            }
            level++;
            continue;
        }

        // Mark* - multiple marking
        if (visited[cp->vtx] == 0)
        {
            visited[cp->vtx] = level;
        }
        else
        {
            if (level % 2 != visited[cp->vtx] % 2)
            {
                return false;
            }
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
    return true;
}

bool isBipertite(vector<vector<Edge *>> &graph)
{
    vector<int> visited(graph.size(), false);
    for (int v = 0; v < graph.size(); v++)
    {
        if (visited[v] == 0)
        {
            bool isTrue = isBipertiteComp(graph, v, visited);
            if (isTrue == false)
            {
                return false;
            }
        }
    }
    return true;
}
/*
void controlGccComp(vector<vector<Edge*>>& graph, int src, vector<bool> visited, vector<int>& comp){
    

    visited[src] = true;
    for(int e = 0; e < graph[src].size(); e++){
        Edge* edge = graph[src][e];
        if(visited[edge->n] == false){
            controlGccComp(graph, edge->n, visited, comp);
        }
    }
    //visited[src] = false;
    comp.push_back(src);
}

void controlGcc(vector<vector<Edge*>>& graph, vector<vector<int>>& comp){
    vector<bool> visited(graph.size(), false);
    for(int v = 0; v < graph.size(); v++){
        if(visited[v] == false){
            vector<int> scomp;
            controlGccComp(graph, v, visited, scomp);
            comp.push_back(scomp);
        }
    }
}
*/

/* Date: 13th April 2019 */

void dijkstras(vector<vector<Edge *>> &graph, int src)
{
    priority_queue<THelper, vector<THelper>, greater<THelper>> pq;
    THelper rh(src, to_string(src), 0);

    pq.push(rh);
    vector<bool> visited(graph.size(), false);

    while (pq.size() > 0)
    {
        THelper ch = pq.top();
        pq.pop();

        if (visited[ch.vtx] == true)
        {
            continue;
        }
        else
        {
            visited[ch.vtx] = true;
        }

        cout << ch.vtx << " via " << ch.psf << " @ " << ch.dsf << endl;

        for (int e = 0; e < graph[ch.vtx].size(); e++)
        {
            Edge *edge = graph[ch.vtx][e];
            int nbr = edge->n;
            int dist = edge->wt;
            if (visited[nbr] == false)
            {
                THelper th(nbr, ch.psf + to_string(nbr), ch.dsf + dist);
                pq.push(th);
            }
        }
    }
}

class PHelper
{
public:
    int vtx;
    int pr;
    int wt;

    PHelper(int vtx, int pr, int wt)
    {
        this->vtx = vtx;
        this->pr = pr;
        this->wt = wt;
    }

    bool operator>(const PHelper &other) const
    {
        return this->wt > other.vtx;
    }
};

void prims(vector<vector<Edge *>> &graph, vector<vector<Edge *>> &mst)
{
    priority_queue<PHelper, vector<PHelper>, greater<PHelper>> pq;
    PHelper rh(0, -1, 0);

    pq.push(rh);
    vector<bool> visited(graph.size(), false);
    while (pq.size() > 0)
    {
        PHelper ch = pq.top();
        pq.pop();

        if (visited[ch.vtx] == true)
        {
            continue;
        }
        else
        {
            visited[ch.vtx] = true;
        }
        if (ch.pr != -1)
        {
            addEdge(mst, ch.vtx, ch.pr, ch.wt);
        }
        for (int e = 0; e < graph[ch.vtx].size(); e++)
        {
            Edge *edge = graph[ch.vtx][e];
            int nbr = edge->n;
            int dist = edge->wt;
            if (visited[nbr] == false)
            {
                PHelper th(nbr, ch.vtx, dist);
                pq.push(th);
            }
        }
    }
}

int countTeams(int n, vector<int> v1, vector<int> v2)
{
    vector<vector<Edge *>> graph2(n);
    for (int i = 0; i < v1.size(); i++)
    {
        addEdge(graph2, v1[i], v2[i], 0);
    }

    // display(graph2);
    vector<vector<int>> comp;
    vector<bool> visited(graph2.size(), false);
    gcc(graph2, comp);

    // cout << "[ ";
    // for(int i = 0; i < comp.size(); i++){
    //     cout << "[";
    //     for(int j = 0; j < comp[i].size(); j++){
    //         cout << comp[i][j] << " ";
    //     }
    //     cout << "], ";
    // }
    // cout << "] " << endl;

    int counter = 0;
    for (int i = 0; i < comp.size(); i++)
    {
        for (int j = i + 1; j < comp.size(); j++)
        {
            counter += comp[i].size() * comp[j].size();
        }
    }

    return counter;
}

//Kruskals Algorithm

class KEdge
{
public:
    int o;
    int n;
    int wt;

    KEdge(int o, int n, int wt)
    {
        this->o = o;
        this->n = n;
        this->wt = wt;
    }

    bool operator>(const KEdge &other) const
    {
        return this->wt > other.wt;
    }
};

int find(vector<int> &dsp, int v)
{
    if (dsp[v] == v)
    {
        return v;
    }
    else
    {
        find(dsp, dsp[v]);
    }
}

void merge(vector<int> &dsp, vector<int> &dra, int v1sl, int v2sl)
{
    if (v1sl < v2sl)
    {
        dra[v1sl] = 0;
        dsp[v1sl] = v2sl;
    }
    else if (v1sl > v2sl)
    {
        dra[v2sl] = 0;
        dsp[v2sl] = v1sl;
    }
    else
    {
        dra[v1sl] = 0;
        dra[v2sl]++;
        dsp[v1sl] = v2sl;
    }
}

void krushkals(vector<vector<Edge *>> &graph)
{
    vector<vector<Edge *>> mst(graph.size());
    priority_queue<KEdge, vector<KEdge>, greater<KEdge>> pq;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            Edge *edge = graph[i][j];
            if (edge->o < edge->n)
            {
                KEdge ke(edge->o, edge->n, edge->wt);
                pq.push(ke);
            }
        }
    }

    // dsp = disjoint set of parent array
    // dra = disjoint rank array
    vector<int> dsp(graph.size());
    vector<int> dra(graph.size());
    // fill arrays
    for (int i = 0; i < dsp.size(); i++)
    {
        dsp[i] = i;
        dra[i] = 1;
    }
    //Work

    while (pq.size() > 0)
    {
        // Remove Edge
        KEdge ke = pq.top();
        pq.pop();
        // Get leader of both edge;
        int v1sl = find(dsp, ke.o);
        int v2sl = find(dsp, ke.n);

        if (v1sl != v2sl)
        {
            addEdge(mst, ke.o, ke.n, ke.wt);
            merge(dsp, dra, v1sl, v2sl);
        }
    }

    display(mst);
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
    // addEdge(graph, 2, 5, 5);
    // display(graph);
    /*    cout << "----------------" << endl;
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
    cout << "----------------" << endl;
    vector<vector<int>> comp;
    gcc(graph, comp);
    cout << "[ ";
    for(int i = 0; i < comp.size(); i++){
        cout << "[";
        for(int j = 0; j < comp[i].size(); j++){
            cout << comp[i][j] << " ";
        }
        cout << "], ";
    }
    cout << "] " << endl;
    cout << "----------------" << endl;
    cout << isConnected(graph) << endl;
    cout << "----------------" << endl;
    cout << isCyclic(graph) << endl;
    cout << "----------------" << endl;
    cout << isTree(graph) << endl;

    cout << "----------------" << endl;
    

    vector<vector<Edge*>> graph1(n);
    addEdge(graph1, 0, 1, 0);
    addEdge(graph1, 0, 2, 0);
    addEdge(graph1, 1, 3, 0);
    addEdge(graph1, 1, 0, 0);
    addEdge(graph1, 3, 2, 0);
    addEdge(graph1, 3, 1, 0);

    // vector<vector<int>> comp1;
    // controlGcc(graph1, comp1);
    // cout << "[ ";
    // for(int i = 0; i < comp1.size(); i++){
    //     cout << "[";
    //     for(int j = 0; j < comp1[i].size(); j++){
    //         cout << comp1[i][j] << " ";
    //     }
    //     cout << "], ";
    // }
    // cout << "] " << endl;
    cout << "===========" << endl;
    cout << isBipertite(graph1) << endl;
*/
    /* Date: 13th April 2019 */
    cout << "---------------" << endl;

    dijkstras(graph, 0);
    vector<vector<Edge *>> mst(n);
    prims(graph, mst);
    display(mst);
    cout << "~~~~~~~~~~~~~~~~" << endl;
    vector<int> v1{1, 4, 3};
    vector<int> v2{4, 2, 5};
    int num = countTeams(6, v1, v2);

    cout << num << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    krushkals(graph);
}