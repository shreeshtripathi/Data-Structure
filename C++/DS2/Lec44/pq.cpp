#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue
{
    private:
        vector<int> list;
        
        void upheapify(int idx)
        {
            if(idx == 0)
            {
                return;
            }
            int ci = idx;
            int pi = (ci - 1) / 2;
            if(list[ci] < list[pi])
            {
                swap(ci,pi);
                upheapify(pi);
            }
        }

        void downHeapify(int idx)
        {
            int minidx = idx;
            int lci = 2 * idx + 1;
            int rci = 2 * idx + 2;

            if(lci < list.size() && list[lci] < list[minidx])
            {
                minidx = lci;
            }
             if( rci < list.size() && list[rci] < list[minidx])
            {
                minidx = rci;
            }
            
            if(minidx != idx){
                swap(minidx, idx);
                downHeapify(minidx);
            }
        }

        void swap(int i, int j)
        {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp; 
        }

    public:
        PriorityQueue()
        {

        }
        PriorityQueue(vector<int>& content)
        {
            // complexity of n
            for(int i = 0; i < content.size(); i++)
            {
                list.push_back(content[i]);
            }

            // complexity of n
            // at lower level in tree there are n / 2 node
            // we call it from upper level
            for(int i = list.size() / 2 - 1; i >= 0; i--)
            {
                downHeapify(i);
            }

        }
        void add(int data)
        {
            list.push_back(data);
            upheapify(list.size() - 1);
        }

        void remove()
        {
            swap(0, list.size() - 1);
            list.pop_back();
            downHeapify(0);
        }

        int peek()
        {
            return list[0];
        }

        int size()
        {
            return list.size();
        }
};

int main(int argc, char** argv)
{
    PriorityQueue pq;
    pq.add(10);
    pq.add(20);
    pq.add(15);
    pq.add(50);
    pq.add(37);
    pq.add(45);
    pq.add(5);

    while(pq.size() > 0)
    {
        int val = pq.peek();
        pq.remove();
        cout << val << " ";
    }
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~" << endl;

    vector<int> vec{20, 5, 4, 17, 7, 80, 9};
    PriorityQueue pq2(vec);
    while(pq2.size() > 0)
    {
        int val = pq2.peek();
        pq2.remove();
        cout << val << " ";
    }
    cout << endl;
}