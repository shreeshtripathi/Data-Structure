#include<iostream>
#include<queue>

using namespace std;

void demo1()
{
    priority_queue<int> pq;
    // priority_queue<int, vector<int>, less<int>> pq;  both are equivalent

    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(3);

    while(pq.size() > 0)
    {
        int val = pq.top(); pq.pop();
        cout << val << " ";
    } 
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void demo2()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(3);

    while(pq.size() > 0)
    {
        int val = pq.top(); pq.pop();
        cout << val << " ";
    } 
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

class car
{
    public:
        string name;
        int price;

        car(string name, int price)
        {
            this->name = name;
            this->price = price;
        }

        // operator overloading for priority queue

        void dispaly()
        {
            
        }

        bool operator<(const car& other) const
        {
            this->price < other.price;
        }

        bool operator>(const car& other) const
        {
            this->price > other.price;
        }
};

void demo3()
{
    priority_queue<car> pq;
    pq.push(car("A", 10));
}
void demo4()
{
    
}

int main(int argc, char** argv)
{
    demo1();
    demo2();
    demo3();
    demo4();
    return 0;
}