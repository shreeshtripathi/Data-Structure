#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

template<typename K, typename V>
class HMNode
{
    public:
        K key;
        V value;
        HMNode(K key, V value)
        {
            this->key = key;
            this->value = value;
        }
};

template<typename K, typename V>
class hashMap
{
    private:
        list<HMNode<K,V>>* buckets = NULL;
        int size;
        int nob;
        int hashfn(K key)
        {
            int hc = hash<K>()(key);
            int bi = abs(hc) % nob;
            return bi;
        }

        typename list<HMNode<K,V>>::iterator findWithinbucket(int bi, K key)
        {
            int di = 0;
            for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++)
            {
                HMNode<K,V> node = *itr;
                if(node.key == key)
                {
                    return itr;
                }
            }
            return buckets[bi].end();
        }

        void rehash(){
            int onob = nob;
            list<HMNode<K, V>>* obuckets = buckets;

            nob = 2 * onob;
            buckets = new list<HMNode<K,V>>[nob];
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
            buckets = new list<HMNode<K, V>>[nob];
            size = 0;
        }

        // for get and put 
        V& operator[](K key)
        {
            int bi = hashfn(key);
            auto itr = findWithinbucket(bi, key);
           
            if(itr == buckets[bi].end())
            {
                HMNode<K,V> node(key, V());
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

        int count(K key)
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

        void erase(K key)
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

        vector<K> keyset(){
            vector<K> keys;
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
    hashMap<string, int> map;
    map["A"] = 1;
    map["B"] = 2;
    map["C"] = 3;
    map["D"] = 4;
    map["E"] = 5;
    map["F"] = 6;
    map["G"] = 7;
    map["H"] = 8;
    map.display();
    map["I"] = 9;
    map.display();

}