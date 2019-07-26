#include<iostream>

using namespace std;

class kstack
{
    private:
        int cap;
        int* da;
        int* pa;
        int* sha;
        int fh;

    public:
        kstack(int cap, int k)
        {
            this->cap = cap;
            this->pa = new int[cap];
            this->da = new int[cap];
            this->sha = new int[k];
            this->fh = 0;

            // set the pointer array in constructor and data array
            for(int i = 0; i < cap; i++)
            {
                da[i] = 0;
                pa[i] = i + 1;
            }
            pa[cap - 1] = -1;
            // set the stack head array at -1
            for(int i = 0; i < k; i++)
            {
                sha[i] = -1;
            }
        }

        bool isFull()
        {
            return this->fh == -1;
        }

        bool isEmpty(int s)
        {
            return sha[s] == -1;
        }

        void push(int val, int s)
        {
            if(isFull())
            {
                cout << "Stack Overflow" << endl;
            }
            else
            {
                int temp = fh;

                fh = pa[temp];
                pa[temp] = sha[s];
                sha[s] = temp;

                da[temp] = val;
            }
        }

        void pop(int s)
        {
            if(isEmpty(s))
            {
                cout << "Stack Underflow" << endl;
            }
            else
            {
                int temp = sha[s];
                
                sha[s] = pa[temp];
                pa[temp] = fh;
                fh = temp;
                
                da[temp] = 0;
            }
        }

        int top(int s)
        {
            if(isEmpty(s))
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            else
            {
                return da[sha[s]];
            }
        }
};


int main(int argc, char** argv)
{
    kstack ks(10, 3);

    ks.push(10, 0);
    ks.push(20, 0);
    ks.push(30, 1);
    ks.push(40, 2);
    ks.push(50, 2);
    ks.push(60, 1);
    ks.push(70, 1);
    ks.push(80, 2);
    ks.push(90, 0);
    ks.push(100, 0);
    ks.push(110, 0);

    for(int i = 0; i <= 2; i++)
    {
        cout << i << ": ";
        while(ks.isEmpty(i) == false)
        {
            int val = ks.top(i); ks.pop(i);
            cout << val << " ";
        }
        cout << endl;
    }
}