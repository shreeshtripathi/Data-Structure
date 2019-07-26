#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

bool duplicateBracket(string& str)
{
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == ')')
        {
            if(st.top() == '(')
            {
                return true;
            }
            else
            {
                while(st.size() > 0 && st.top() != '(')
                {
                    st.pop();
                }
                st.pop();   
            }
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}


int main(int argc, char** argv)
{
    string str1 = "((a+b)+((c+d)))";
    string str2 = "((a+b)+((c+d)+e))";
    cout << duplicateBracket(str1) << endl;
    cout << duplicateBracket(str2) << endl;
}