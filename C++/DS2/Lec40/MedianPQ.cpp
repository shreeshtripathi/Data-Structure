#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MedianPQ
{
    private:
        priority_queue<int, vector<int>, greater<int>> right;
        priority_queue<int, vector<int>, less<int>> left;
        void handleBalace(){
            if(left.size() - right.size() == 2)
            {
                int val = left.top();
                left.pop();
                right.push(val);
            }
            else if(right.size() - left.size() == 2)
            {
                int val = right.top();
                right.pop();
                left.push(val);
            }
        }

    public:
        void push(int data)
        {
            if(left.size() > 0 && data < left.top()){
                left.push(data);
            }
            else
            {
                right.push(data);
            }
            handleBalace();
        }

        void pop()
        {
            if(left.size() >= right.size())
            {
                left.pop();
            }
            else
            {
                right.pop();
            }
        }

        int top()
        {
            if(left.size() >= right.size())
            {
                return left.top();
            }
            else
            {
                return right.top();
            }
        }
        
        int size()
        {
            return left.size() + right.size();
        }

};

int main(int argv, char** argc)
{
    MedianPQ pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(50);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    pq.push(80);
    cout << pq.top() << endl;
    pq.push(100);
    pq.push(110);
    cout << pq.top() << endl;

    while(pq.size() > 0) {
        int val=pq.top();
        pq.pop();
        cout<<val<<endl;
    }
}