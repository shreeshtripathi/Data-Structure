#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

class Edge
{
    public:
        int u;
        int v;
        int wt;
        Edge(int u, int v, int wt)
        {
            this->u = u;
            this->v = v;
            this->wt = wt;
        }
};


int main(int argc, char** argv)
{
    vector<Edge> graph;
    graph.push_back(Edge(0, 1, 2));
    graph.push_back(Edge(1, 2, 3));
    graph.push_back(Edge(2, 3, 4));
    graph.push_back(Edge(3, 4, 5));
    graph.push_back(Edge(4, 2, -6));
    graph.push_back(Edge(4, 5, 4));
    graph.push_back(Edge(5, 6, -10));
    graph.push_back(Edge(6, 3, 2));

    int src = 0;
    vector<pair<int, string>> result(7, make_pair(INT_MAX, ""));
    result[0].first = 0;
    result[0].second = ".";

    // loop is run V - 1 times
    // by then paths of 1 length long, 2 length long, and so on... till v - 1 length will be consider
    // it needs to be done because a vertex may be v - 1 edges away from the src

    for(int v = 0; v < 7 - 1; v++)
    {
        // before Vth iteartion we have paths at-least V edges long
        // after Vth iteration we have paths at-least V + 1 edges long+


        for(int e = 0; e < graph.size(); e++)
        {
            Edge edge = graph[e];
            // optimise it like sv = su + uv
            if(result[edge.u].first != INT_MAX &&
            result[edge.u].first + edge.wt < result[edge.v].first)
            {
                result[edge.v].first = result[edge.u].first + edge.wt;
                result[edge.v].second = result[edge.u].second + to_string(edge.v);
            }
        }
    }


    // Vth iteration - this loop is creating paths V length long
    // v length long paths have cycles
    // if an optimisation now occurs, means you have found an optimised alternate path of length v(cyclic)
    // to an already visited vertex -> negative cycle

    for(int e = 0; e < graph.size(); e++)
    {
        Edge edge = graph[e];
        // optimise it like sv = su + uv
        if(result[edge.u].first != INT_MAX &&
        result[edge.u].first + edge.wt < result[edge.v].first)
        {
            cout << "Cycle Detection" << endl;
            return 0;
        }
    }
    
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i].second << " @ " << result[i].first << endl;
    }

}