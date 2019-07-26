#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void stockSpan(vector<int>& stock)
{
    // calculate greater element in left side of array
    vector<int> pge(stock.size(), 0);
    stack<int> st;
    pge[0] = -1;
    st.push(0);

    for(int i = 1; i < stock.size(); i++)
    {
        while(st.size() > 0 && stock[st.top()] < stock[i])
        {
            st.pop();
        }
        pge[i] = st.size() > 0 ? st.top(): -1;
        st.push(i);
    }

    // calculate stock span array from nge array and stock array
    // i.e.  = (idex of stock array - nge[current index])
    vector<int> span(pge.size(), 0);
    for(int i = 0; i < stock.size(); i++)
    {
        span[i] = i - pge[i];
    }

    for(int val : span)
    {
        cout  << val << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    vector<int> stock{3, 8, 6, 2, 7, 11, 5, 4, 1, 10, 9};
    stockSpan(stock);
}