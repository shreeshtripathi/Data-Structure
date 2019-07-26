#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class intervals
{
    public:
        int start;
        int end;
        char act;
    intervals(int start, int end, char act)
    {
        this->start = start;
        this->end = end;
        this->act = act;
    }

    bool operator>(const intervals& ot) const
    {
        return this->end > ot.end;
    }
};

int main(int argc, char** argv)
{
    priority_queue<intervals, vector<intervals>, greater<intervals>> pq;
    vector<int> str {3, 0, 1 , 8, 5, 5};
    vector<int> en {4, 6, 2, 9, 9, 7};
    vector<char> ac {'a', 'b', 'c', 'd', 'e', 'f'};

    for(int i = 0; i < str.size(); i++)
    {
        pq.push(intervals(str[i], en[i], ac[i]));
    }

    int count = 1;
    intervals first = pq.top(); pq.pop();
    // cout << first.act << endl;
    string ans = string() + first.act;
    // cout << ans << endl;
    for(int i = 1; i < ac.size(); i++)
    {
        intervals afirst = pq.top(); pq.pop();
        if(afirst.start > first.end)
        {
            count++;
            ans += afirst.act;
            first = afirst;
        }
    }
    cout << count << " " << ans << endl;
    return 0;
}