#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class PriorityQueue
{
    private:
        vector<T> list;
        
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
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp; 
        }

    public:
        PriorityQueue()
        {

        }
        PriorityQueue(vector<T>& content)
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
        void add(T data)
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

        T peek()
        {
            return list[0];
        }

        int size()
        {
            return list.size();
        }
};

class Car
{
    public:
        int speed;
        int price;
        string name;

        Car(int speed, int price, string name)
        {
            this->name = name;
            this->price = price;
            this->speed = speed;
        }

        bool operator<(const Car& other)const
        {
            return this->price < other.price;    
        }
        
        void display()
        {
            cout << price << " " << speed << " " << name << endl;
        }
};

int main(int argc, char** argv)
{
    PriorityQueue<Car> pq;
    Car c1(10, 100, "A");
    Car c2(20, 200, "B");
    Car c3(15, 1000, "C");
    Car c4(100, 400, "D");
    Car c5(5, 150, "E");

    pq.add(c1);
    pq.add(c2);
    pq.add(c3);
    pq.add(c4);
    pq.add(c5);

    while(pq.size() > 0)
    {
        Car  c = pq.peek();
        c.display();
        pq.remove();
    }
}