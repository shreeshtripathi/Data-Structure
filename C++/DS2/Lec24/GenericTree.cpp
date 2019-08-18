#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Node{
    public:
        int data;
        vector<Node*> children;
        Node(int data){
            this->data = data;
        }
};

Node* build(vector<int> dlist) {
    Node* root = NULL;
    vector<Node*> nlist;
    for(int i = 0; i < dlist.size(); i++) {
        if(dlist[i] == -1) {
            nlist.pop_back();
        } else {
            Node* nn = new Node(dlist[i]);
            if(nlist.size() == 0) {
                root = nn;
            } else {
                Node* lastN = nlist.back();
                lastN->children.push_back(nn);
            }
            nlist.push_back(nn);
        }
    }
    return root;
}

void display(Node* root) {
    string s = to_string(root->data) + "->" ;
    for(int i = 0; i < root->children.size(); i++) {
        s += to_string(root->children[i]->data) + ",";
    }
    cout << s << "." << endl;
    for(int i = 0; i < root->children.size(); i++) {
        display(root->children[i]);
    }
}

int size(Node* root) {
    int count = 0;
    for(int i = 0; i < root->children.size(); i++) {
        count += size(root->children[i]);
    }
    count++;
    return count;
}

int mymax(Node* root) {
    int m = root->data;
    for(int i = 0; i < root->children.size(); i++) {
        int temp = mymax(root->children[i]);
        m = max(m,temp);
    }
    return m;
}
bool find(Node* root, int data) {
    if(root->data == data) {
        return true;
    }
    bool isHere = false;
    for(int i = 0; i < root->children.size(); i++) {
        isHere = find(root->children[i], data);
        if(isHere) {
            return true;
        }
    }
    return false;
}

int height(Node* root) {
    int maxH = 0; // if want height in terms of edges then initialise it from -1
    for(int i = 0; i < root->children.size(); i++) {
        int temp = height(root->children[i]);
        if(temp > maxH) {
            maxH = temp;
        }
    }
    maxH++;
    return maxH;
}

vector<int>* nodeToRootPath(Node* root, int dtf){
    if(root->data == dtf){
        vector<int>* bres = new vector<int>();
        bres->push_back(root->data);
        return bres;  
    }

    for(int i = 0; i < root->children.size(); i++){
        vector<int>* n2cpath =  nodeToRootPath(root->children[i], dtf);
        if(n2cpath != NULL){
            n2cpath->push_back(root->data);
            return n2cpath;
        }
    }

    return NULL;
}

//lca = lowest common ancestor
int lca(Node* root, int data1, int data2){
    vector<int>* path1 = nodeToRootPath(root, data1);
    vector<int>* path2 = nodeToRootPath(root, data2);

    int s1 = path1->size() - 1;
    int s2 = path2->size() - 1;

    int prev;
    while(s1 >=0 && s2 >=0 && (*path1)[s1] == (*path2)[s2]){
        prev = (*path1)[s1];
        s1--;
        s2--;
    }
    return prev;
}

int distance(Node* root, int data1, int data2){
    vector<int>* path1 = nodeToRootPath(root, data1);
    vector<int>* path2 = nodeToRootPath(root, data2);

    if(path1 == NULL || path2 == NULL){
        cout << " invalid ";
        return -1;
    }

    int s1 = path1->size() - 1;
    int s2 = path2->size() - 1;

    while(s1 >=0 && s2 >=0 && (*path1)[s1] == (*path2)[s2]){
        s1--;
        s2--;
    }
    return (s1 + 1) + (s2 + 1) + 1;
}

void mirror(Node* root){
    for(int i = 0; i < root->children.size(); i++){
        mirror(root->children[i]);
    }
    
    int left = 0;
    int right = root->children.size() - 1;

    while(left < right){
        Node* ln = root->children[left];
        Node* rn = root->children[right];
        root->children[left] = rn;
        root->children[right] = ln;

        left++;
        right--;
    }
}


int main(){
    vector<int> dlist{
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = build(dlist);
    
    //display(root);

    cout << "Size = ----" << size(root) << "------" << endl;
	
    cout << "Max = ----" <<  mymax(root) << "------" << endl;
	
    cout << "Find(100)  = ----" << find(root, 100) << "-----" << endl;
	
    cout << "Height = ----" << height(root) << "------" << endl;
    
    cout << "Node to root path (120) --- ";
    vector<int>* path = nodeToRootPath(root, 120);
    for(int i = 0; i < path->size(); i++){
        cout << (*path)[i] << " ";
    }
    cout << endl;

    cout << "lca = ----" << lca(root, 70, 90) << "----" << endl;
    
    cout << "distance = ----" << distance(root, 50, 100) << "----" << endl;

    display(root);
    cout << "---------- M-I-R-R-O-R ----------" << endl;
    mirror(root);
    display(root);

    
    return 0;
}