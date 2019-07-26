#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

vector<int> calLeftBound(vector<int>& v)
{
    vector<int> res(v.size(), 0);
    stack<int> st;
    st.push(0);
    res[0] = -1;
    for(int i = 1; i < v.size(); i++)
    {
        while(st.size() > 0 && v[i] < v[st.top()])
        {
            st.pop();
        }
        // either the satck is empty or the element at top is > v[i]

        res[i] = st.size() > 0? st.top():-1;
        st.push (i);
    }
    return res;
}

vector<int> calRightBound(vector<int>& v)
{
    vector<int> res(v.size(), 0);
    stack<int> st;
    st.push(v.size() - 1);
    res[v.size() - 1] = v.size();
    for(int i = v.size() - 2; i >= 0; i--)
    {
        while(st.size() > 0 && v[i] < v[st.top()])
        {
            st.pop();
        }
        // either the satck is empty or the element at top is > v[i]

        res[i] = st.size() > 0? st.top():v.size();
        st.push (i);
    }
    return res;
}

int largestAreaHistogram(vector<int>& ques)
{
    vector<int> left = calLeftBound(ques);
    cout << "~~~~~~~~~~~~~ left ~~~~" << endl;
    for(int i = 0; i < left.size(); i++)
    {
        cout << left[i] << " ";
    }
    cout << endl;
    vector<int> right = calRightBound(ques);
    cout << "~~~~~~~~~~~~~ right ~~~~" << endl;
    for(int i = 0; i < left.size(); i++)
    {
        cout << right[i] << " ";
    }
    cout << endl;
    int max = -1;
    for(int i = 0; i < ques.size(); i++)
    {
        int carea = ques[i] * (right[i] - left[i] - 1);
        if(carea > max)
        max = carea;
        
    }
    return max;
}

int main(int argc, char** argv)
{
    vector<int> q{6, 2, 5, 4, 5, 1, 6};
    cout << largestAreaHistogram(q) << endl;
}