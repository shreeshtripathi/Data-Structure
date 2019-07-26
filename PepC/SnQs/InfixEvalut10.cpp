#include<bits/stdc++.h>

using namespace std;

int evaluate(int val1, int val2, char op)
{
    if(op == '+')
        return val1 + val2;
    else if(op == '-')
        return val1 - val2;
    else if(op == '*')
        return val1 * val2;
    else if(op == '/')
        return val1 / val2;
    else if(op == '^')
        return pow(val1, val2);
}

int infixEvaluation(string str)
{
    //set priorities of operator, also can be doable from an additional function
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;

    stack<char> op;
    stack<int> val;

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch >= '0' && ch <= '9'){
            val.push(ch - '0');
        }
        else if(ch == '('){
            op.push(ch);
        }
        else if(ch == ')')
        {
            while(!(op.top() == '('))
            {
                char opr = op.top(); op.pop();
                int v2 = val.top(); val.pop();
                int v1 = val.top(); val.pop();
                int ans = evaluate(v1, v2, opr);
                val.push(ans);
            }
            op.pop();
        }
        
        else
        {
            while(!(op.size() ==0 || op.top() == '(' || mp[op.top()] < mp[ch]))
            {
                char opr = op.top(); op.pop();
                int v2 = val.top(); val.pop();
                int v1 = val.top(); val.pop();
                int ans = evaluate(v1, v2, opr);
                val.push(ans);
            }
            op.push(ch);
        }
    }

    while(op.size() > 0)
        {
            char opr = op.top(); op.pop();
            int v2 = val.top(); val.pop();
            int v1 = val.top(); val.pop();
            int ans = evaluate(v1, v2, opr);
            val.push(ans);
        }

    return val.top();
}


// cpnversion from infix to postfix
string infixToPostfix(string str)
{
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;

    string postfix;
    stack<char> st;

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '(')
            {
                char opr = st.top();
                st.pop();
                postfix += opr;
            }
            st.pop();
        }
        else if(ch >= '0' && ch <= '9')
        {
            postfix += ch;
        }
        else
        {
            while(st.size() && st.top() != '(' && mp[st.top()] > mp[ch])
            {
                char opr = st.top();
                st.pop();
                postfix += opr;
            }
            st.push(ch);
        }
    }
    while(st.size() > 0)
    {
        char ch = st.top();
        st.pop();
        postfix += ch;
    }
    return postfix;
}

string reverseString(string str)
{
    string res;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] == '(')
        {
            res += ')';
        }
        else if(str[i] == ')')
        {
            res += '(';
        }
        else
        {
            res += str[i];
        }
    }
    return res;
}

string infixToPrefix(string str)
{
    // reverse the infix expression and correct the opening bracket and closing bracket
    str = reverseString(str);
    // calculate postfix of that expression
    str = infixToPostfix(str);
    // reverse the answer of postfix expression
    str = reverseString(str);
    return str;
}


int main(int argc, char** argv)
{
    string str1 = "8+2/3+2^1*(1+3)";
    string str2 = "(8+2)/3+2^(1*1+3)";

    cout << infixEvaluation(str1) << " " << infixToPostfix(str1) << "   " << infixToPrefix(str1) << endl;
    cout << infixEvaluation(str2) << " " << infixToPostfix(str2) << "   " << infixToPrefix(str2) << endl;

}