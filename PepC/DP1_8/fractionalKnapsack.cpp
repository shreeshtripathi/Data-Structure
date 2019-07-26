#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class WtvsVal
{
    public:
        int wt;
        int val;
        double ratio;

        WtvsVal(int wt, int val)
        {
            this->wt = wt;
            this->val = val;
            this->ratio = val * 1.0 / wt;
        }

        bool operator<(const WtvsVal& other) const
        {
            return this->ratio < other.ratio;
        }

};

int main(int argc, char** argv)
{
    priority_queue<WtvsVal> pq;

    vector<int> wt {10, 40, 20, 30};
    vector<int> val {60, 40, 100, 120};
    int cap = 50;
    for(int i = 0; i < wt.size(); i++)
    {
        pq.push(WtvsVal(wt[i], val[i]));
    }
    
    double vib = 0; // value in bag
    int rc = cap; // remaining capacity

    while(pq.size() > 0)
    {
        WtvsVal rem = pq.top(); pq.pop();
        if(rc >= rem.wt)
        {
            vib += (rem.ratio * rem.wt);
            rc -= rem.wt;
        }
        else
        {
            vib += rc*rem.ratio;
            rc = 0;
            break;
        }
    }

    cout << vib << endl;

}