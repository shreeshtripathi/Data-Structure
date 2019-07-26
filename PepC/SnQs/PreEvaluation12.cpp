#include<bits/stdc++.h>

using namespace std;

int evaluate(int val1, int val2, char op)
{
    if(op == '+')
        return val1 + val2;
    else if(op == '-')
        return val1 - val2;
    else if(op == '/')
        return val1 / val2;
    else if(op == '*')
        return val1 * val2;
    else
        return pow(val1, val2);
}

void pre123(string str)
{
    stack<int> pres;
    stack<string> ins;
    stack<string> pos;

    for(int i = str.size() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if(ch >= '0' && ch <= '9'){
            pres.push(ch - '0');

            ins.push(string() + ch);

            pos.push(string() + ch);
        }
        else
        {
            int val1 = pres.top(); pres.pop();
            int val2 = pres.top(); pres.pop();
            pres.push(evaluate(val1, val2, ch));

            string str1 = ins.top(); ins.pop();
            string str2 = ins.top(); ins.pop();
            ins.push('(' + str1 + ch + str2 + ')');

            string str21 = pos.top(); pos.pop();
            string str22 = pos.top(); pos.pop();
            pos.push(str21 + str22 + ch);

        }
        
    }

    cout << pres.top() << endl;
    cout << ins.top() << endl;
    cout << pos.top() << endl;
}

int main(int argc, char** argv)
{
    string str1 = "-/24^32";
    pre123(str1);
}