#include<bits/stdc++.h>

using namespace std;

bool matchingBracket(string str)
{
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == ')' || ch == '}' || ch == ']')
        {
            char cb;
            if(ch == ')')
                cb = '(';
            else if(ch == '}')
                cb = '{';
            else
                cb = '[';
            
            while(st.size() > 0 && st.top() != cb)
            {
                st.pop();
            }
            if(st.size() > 0)
            {
                st.pop();
            }
            else
            {
                return false;
            }
            
        }
        else
        {
            st.push(ch);
        }
    }
    if(st.size() > 0)
        return false;
    else
        return true;
    
}

int main(int argc, char** argv)
{
    cout << matchingBracket("[{(a+b)+(c+d)}]") << endl;
    cout << matchingBracket("[{(a+b)+(c+d})]") << endl;
    cout << matchingBracket("[{(a+b)+(c+d)}") << endl;
    cout << matchingBracket("{(a+b)+(c+d)}]") << endl;
}