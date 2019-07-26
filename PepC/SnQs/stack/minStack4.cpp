#include<iostream>
#include<stack>
#include<climits>

using namespace std;

/*
worst case
class minStack
{
    private:
        stack<int> mst;
        stack<int> dst;
        int min = INT_MAX;
    public:
        minStack()
        {

        }

        void push(int val)
        {
            if(val <= min)
            {
                mst.push(val);                
            }
            dst.push(val);
        }

        void pop()
        {
            if(dst.top() == mst.top())
            {
                mst.pop();
            }
        }

        int top()
        {
            return dst.top();
        }

        int size()
        {
            return dst.size();
        }

        int min()
        {
            return mst.top();
        }
    
};
*/
int main()
{
    // minStack mn;
    // mn.push(5);
    // mn.push(3);
    // mn.push(2);
    // mn.push(7);
    // mn.push(8);
    // mn.push(11);
    // mn.push(10);
}