#include <iostream>
#include <queue>

using namespace std;

int main(int argv, char **argc)
{

    // priority_queue<int> pq;    both these are same and by default it give large value first
    // priority_queue<int, vector<int>, less<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(19);
    pq.push(20);
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(25);
    while (pq.size() > 0)
    {
        int top = pq.top();
        pq.pop();

        cout << top << endl;
    }
}