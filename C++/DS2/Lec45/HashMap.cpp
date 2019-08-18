#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

class HMNode
{
    public:
        int key;
        string value;
        HMNode(int key, string value)
        {
            this->key = key;
            this->value = value;
        }
};

class hashMap
{
    private:
        list<HMNode>* buckets = NULL;
        int size;
        int nob;
        int hashfn(int key)
        {
            int hc = key;
            int bi = abs(hc) % nob;
            return bi;
        }

        list<HMNode>::iterator findWithinbucket(int bi, int key)
        {
            int di = 0;
            for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++)
            {
                HMNode node = *itr;
                if(node.key == key)
                {
                    return itr;
                }
            }
            return buckets[bi].end();
        }

        void rehash(){
            int onob = nob;
            list<HMNode>* obuckets = buckets;

            nob = 2 * onob;
            buckets = new list<HMNode>[nob];
            size = 0;

            for(int bi = 0; bi < onob; bi++)
            {
                for(auto di = obuckets[bi].begin(); di != obuckets[bi].end(); di++)
                {
                    (*this)[di->key] = di->value;
                }
            }
            delete[] obuckets;
        }
    public:

        hashMap()
        {
            nob = 4;
            buckets = new list<HMNode>[nob];
            size = 0;
        }

        // for get and put 
        string& operator[](int key)
        {
            int bi = hashfn(key);
            auto itr = findWithinbucket(bi, key);
            if(itr == buckets[bi].end())
            {
                HMNode node(key, "");
                buckets[bi].push_back(node);
                size++;

                double lambda = (size * 1.0 )/ nob;
                if(lambda > 2.0)
                {
                    rehash();
                }

                bi = hashfn(key);
                itr = findWithinbucket(bi, key);
                return itr->value;
            }
            else
            {
                return itr->value;
            }
        }

        int count(int key)
        {
            int bi = hashfn(key);
            auto itr = findWithinbucket(bi, key);
            if(itr == buckets[bi].end())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        void erase(int key)
        {
            int bi = hashfn(key);
            auto itr = findWithinbucket(bi, key);
            if(itr == buckets[bi].end()){
                return;
            }
            else
            {
                size--;
                buckets[bi].erase(itr);
            }
        }

        vector<int> keyset(){
            vector<int> keys;
            for(int bi = 0; bi < nob; bi++){
                for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++)
                {
                    keys.push_back(itr->key);
                }
            }
            return keys;
        }

        void display()
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            for(int bi = 0; bi < nob; bi++)
            {
                cout << "b" << bi << " -> ";
                for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++)
                {
                    cout << "[" << itr->key << ", " << itr->value << "]" << " ,";
                }
                cout << "." << endl;
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

};


int main(int argv, char** argc)
{
    hashMap map;
    map[1] = "A";
    map[2] = "B";
    map[3] = "C";
    map[4] = "D";
    map[5] = "E";
    map[6] = "F";
    map[7] = "G";
    map[8] = "H";
    map.display();
    map[9] = "I";
    map.display();

}