//code - minimum square can be cutted from a rectangle
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int SquareCut(int l, int b, vector<vector<int>> &qb)
{

    if (l == 0 || b == 0)
    {
        return 0;
    }

    if (l == b)
    {
        return 1;
    }

    if (qb[l][b] != 0)
    {
        return qb[l][b];
    }

    // smallest dimension , which is equal to min of l and b
    int sd = min(l, b);
    int res = INT_MAX;
    for (int x = 1; x <= sd; x++)
    {
        int p1v = SquareCut(x, b - x, qb);
        int p2v = SquareCut(l - x, b, qb);
        int p1h = SquareCut(l - x, x, qb);
        int p2h = SquareCut(l, b - x, qb);
        res = min(res, min(p1v + p2v + 1, p1h + p2h + 1));
    }

    qb[l][b] = res;
    return res;
}

void SqCutBase(int l, int b)
{
    vector<vector<int>> qb(l + 1, vector<int>(b + 1, 0));
    int res = SquareCut(l, b, qb);
    cout << res << endl;
}

int main(int argc, char **argv)
{
    SqCutBase(36, 30);
}