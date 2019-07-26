#include<iostream>

using namespace std;

class twoStack
{  
    private:
        int* data;
        int cap;
        int tos1;
        int tos2;
    
    public:
        twoStack(int cap)
        {
            this->data = new int[cap];
            this->cap = cap;
            this->tos1 = -1;
            this->tos2 = cap;
        }

        void push1(int val)
        {
            if(this->isFull())
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            tos1++;
            data[tos1] = val;

        }

        void push2(int val)
        {
            if(this->isFull())
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            tos2--;
            data[tos2] = val;
        }

        void pop1()
        {
            data[tos1] = 0;
            tos1--;
        }

        void pop2()
        {
            data[tos2] = 0;
            tos2++;
        }

        int top1()
        {
            int val = data[tos1];
            return val;
        }

        int top2()
        {
            int val = data[tos2];
            return val;
        }

        bool isEmpty1()
        {

        }

        bool isEmpty2()
        {

        }

        bool isFull()
        {
            if(tos2 = tos1 + 1)
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

}