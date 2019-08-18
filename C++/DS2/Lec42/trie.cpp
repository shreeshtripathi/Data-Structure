#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>

using namespace std;

class Node
{
    public:
        char data;
        bool eow;   // end of word show the existence
        unordered_map<char, Node*> cmap;

        Node(char data, bool eow)
        { 
            this->data = data;
            this->eow = eow;
        }
};

bool searchWord(Node* root, string word)
{
    if(word.size() == 0)
    {
        return root->eow;
    }
    char ch = word[0];
    string row = word.substr(1);
    if(root->cmap.count(ch) == 0){
        return false;
    }
    else 
    {
        Node* child = root->cmap[ch];
        return searchWord(child, row);
    }
}

void addWord(Node* root, string word)
{
    if(word.size() == 0)
    {
        root->eow = true;
        return;
    }
    char cw = word[0];
    string row = word.substr(1);
    if(root->cmap.count(cw) == 0)
    {
        Node* child = new Node(cw, false);
        root->cmap[cw] = child;
        addWord(child, row);
    }
    else
    {
        addWord(root->cmap[cw], row);
    }
    
}

void removeWord(Node* root, string word)
{
    if(word.size() == 0)
    {
        root->eow = false;
        return;
    }
    char ch = word[0];
    string row = word.substr(1);
    Node* child = root->cmap[ch];
    removeWord(child, row);

    if(child->eow == false && child->cmap.size() == 0)
    {
        root->cmap.erase(ch);
        delete child;
    }
}

void displayWords(Node* root, string wsf)
{
    if(root->eow == true)
    {
        cout << wsf << ", ";
    }
    for(auto itr = root->cmap.begin(); itr != root->cmap.end(); itr++)
    {
        displayWords(itr->second, wsf + itr->first);
    }
}

void displayTrie(Node* root)
{
    cout << "[" << root->data  << " " << root->eow << "] - ";
    for(auto itr = root->cmap.begin(); itr != root->cmap.end(); itr++)
    {
        cout << itr->first << ", ";
    }
    cout << "." << endl;
    for(auto itr = root->cmap.begin(); itr != root->cmap.end(); itr++)
    {
        displayTrie(itr->second);
    }
}


int main(int argv, char** argc)
{
    Node* root = new Node('$', false);
    addWord(root, "are");
    addWord(root, "art");
    addWord(root, "as");
    addWord(root, "ask");
    addWord(root, "ant");
    addWord(root, "an");
    addWord(root, "and");
    addWord(root, "seen");
    addWord(root, "sea");
    addWord(root, "see");
    // displayWords(root, "");
    // cout << endl;
    // removeWord(root, "as");
    // displayTrie(root);
    // cout << "~~~~~~~~~~~~~~~~~" << endl;
    // removeWord(root, "ask");
    // displayTrie(root);
    cout << searchWord(root, "seen") << endl;

}
