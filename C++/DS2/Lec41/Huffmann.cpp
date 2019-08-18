#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;

class Node
{
    public:
        char data;
        int freq;
        Node* left = NULL;
        Node* right = NULL;
       
        Node(char data, int freq)
        {
            this->freq = freq;
            this->data = data;
        }

        Node(const Node& n)
        {
            this->freq = n.freq;
            this->data = n.data;
            this->left = n.left;
            this->right = n.right;
        }

        bool operator>(const Node& other) const
        {
            return this->freq > other.freq; 
        }
};

class Huffmann
{
    public:
        unordered_map<char, string> encoder;
        unordered_map<string, char> decoder;

        void traverse(Node* root, string asf)
        {
            if(root->left == NULL && root->right == NULL)
            {
                encoder[root->data] = asf;
                decoder[asf] = root->data;
                return;
            }
            traverse(root->left, asf + "0");
            traverse(root->right, asf + "1");
        }

        Huffmann(string str)
        {
            // prepare a frequency map

            unordered_map<char, int> fqmp;
            for(int i = 0; i < str.size(); i++)
            {
                fqmp[str[i]] = fqmp.count(str[i]) == 0 ? 1 : fqmp[str[i]] + 1;
            }
            // make priority queue and fill it;
            priority_queue<Node, vector<Node>, greater<Node>> pq;

            for(auto itr = fqmp.begin(); itr != fqmp.end(); itr++)
            {
                Node n1(itr->first, itr->second);
                pq.push(n1);
            }

            // Process the priority queue and make a tree
            while(pq.size() > 1)
            {
                Node n1 = pq.top();
                pq.pop();
                Node n2 = pq.top();
                pq.pop();
                Node n3('#', n1.freq + n2.freq);
                n3.left = new Node(n1);
                n3.right = new Node(n2);
                pq.push(n3);
            }
            Node root = pq.top();
            pq.pop();
            traverse(&root, "");
        }

        string encode(string str)
        {
            string ans = "";
            for(int i = 0; i < str.length(); i++)
            {
                ans += encoder[str[i]];
            }
            return ans;
        }

        string decode(string str)
        {
            string s = "";
            string ans = "";
            for(int i = 0; i < str.size(); i++)
            {
                s += str[i];
                if(decoder.count(s) == 1)
                {
                    ans += decoder[s];
                    s = "";
                }
            }
            return ans;
        }
};

int main(int argv, char** argc)
{
    string str = "abcd";
    Huffmann hm(str);
    string str1 = "aabbcdd";
    cout << hm.encode(str1) << endl;

    cout << "~~~~~~~~~~~`" << endl;
    cout << hm.decode("01011111100000") << endl;   
}