#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Intervals
{
    public:
        int start;
        int end;

        Intervals(int start, int end)
        {
            this->start = start;
            this->end = end;
        }

        bool operator<(const Intervals& other) const
        {
            return this->start < other.start;
        }
};

void overlapIntrvl(vector<int>& starts, vector<int>& ends)
{
    vector<Intervals> intrvls;
    for(int i = 0; i < starts.size(); i++)
    {
        Intervals intvl(starts[i], ends[i]);
        intrvls.push_back(intvl);
    }

    sort(intrvls.begin(), intrvls.end());
    stack<Intervals> st;
    st.push(intrvls[0]);

    for(int i = 1; i < intrvls.size(); i++)
    {
        if(intrvls[i].start <= st.top().end)
        {
            st.top().end = max(st.top().end, intrvls[i].end);
        }
        else
        {
            st.push(intrvls[i]);
        }
    }

    cout << "[";
    while(st.size() > 0)
    {
        cout << st.top().start << "-" << st.top().end<<", ";
        st.pop();
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> starts{22, 17, 19, 2, 6, 12, 3};
    vector<int> ends{26, 20, 23, 4, 9, 15, 7};
    overlapIntrvl(starts, ends);
}