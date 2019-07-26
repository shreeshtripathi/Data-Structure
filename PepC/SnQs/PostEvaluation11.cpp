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

void post123(string post)
{
    stack<int> evs;
    stack<string> ins;
    stack<string> pres;

    for(int i = 0; i < post.size(); i++)
    {
        char ch = post[i];
        if(ch >= '0' && ch <= '9')
        {
            evs.push(ch - '0');
            ins.push(string() + ch);
            pres.push(string() + ch);
        }
        else
        {
            int val2 = evs.top(); evs.pop();
            int val1 = evs.top(); evs.pop();
            evs.push(evaluate(val1, val2, ch));

            string str2 = ins.top(); ins.pop();
            string str1 = ins.top(); ins.pop();
            ins.push('(' + str1 + ch + str2 + ')');

            string str21 = pres.top(); pres.pop();
            string str22 = pres.top(); pres.pop();
            pres.push( ch + str21 + str22);

        }
    }


    cout << evs.top() << endl;
    cout << ins.top() << endl;
    cout << pres.top() << endl;
}


int main(int argc, char** argv)
{
    string post = "24/32^-";
    post123(post);
    return 0;
}