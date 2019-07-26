#include<iostream>

using namespace std;

class mystack
{
private:
    int* data;
    int tos;
    int cap;

public:
    mystack(int cap)
    {
        this->data = new int[cap];
        this->cap = cap;
        this->tos = -1;
    }

    void push(int val)
    {  
        if(tos == cap - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        tos++;
        data[tos] = val;
    }

    void pop()
    {
        if(tos == -1)
        {
            cout << "stack underflow" << endl;
            return;
        }   
        data[tos] = 0;
        tos--;
    }

    int size()
    {
        return tos + 1;
    }

    int top()
    {
        if(tos == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }   
        int val = data[tos];
        return val;
    }

    bool isEmpty()
    {
        if(tos == -1)
        {
            return true;
        }
        else
        {
            return false;
        }   
    }
};

int main(int argc, char** argv)
{
    mystack ms(5);

    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);

    ms.push(60);

    while(ms.size() > 0)
    {
        int val = ms.top(); ms.pop();
        cout << val << endl;
    }
    ms.pop();
}