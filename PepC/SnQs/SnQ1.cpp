#include<iostream>
#include<stack>
#include<string>
using namespace std;

void ddid(string str)
{
    stack<int> st;
    int val = 1;
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        st.push(val++);
        if(ch == 'i')
        {
            while(st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    st.push(val++);
    while(st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    ddid("iddiidid");
    ddid("dddddddd");
    ddid("iiiiiiii");
    return 0;
}