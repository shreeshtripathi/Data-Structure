#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

void nge(vector<int>& v)
{
    vector<int> res(v.size(), 0);
    stack<int> st;
    st.push(v[v.size() - 1]);
    res[v.size() - 1] = -1;
    for(int i = v.size() - 2; i >= 0; i--)
    {
        while(st.size() > 0 && v[i] > st.top())
        {
            st.pop();
        }
        // either the satck is empty or the element at top is > v[i]

        res[i] = st.size() > 0? st.top():-1;
        st.push (v[i]);
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}


void nge2(vector<int>& v)
{
    vector<int> res(v.size(), 0);
    stack<int> st;
    st.push(0);

    for(int i = 0; i < v.size(); i++)
    {
        while(st.size() > 0 && v[st.top()] < v[i])
        {
            res[st.top()] = v[i];
            st.pop();
        }

        st.push(i);
    }
    while(st.size() > 0)
    {
        res[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    vector<int> v{3, 1, 2, 4, 5};
    nge(v);
    nge2(v);
    return 0;
}