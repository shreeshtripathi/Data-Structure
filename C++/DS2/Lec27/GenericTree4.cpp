#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
//Include linkedlist for level order
#include<list>
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


/* DATE : 28th March 2019 */

Node* linearize(Node* root){
    if(root->children.size() == 0){
        return root;
    }

    Node* ol = root->children[root->children.size() - 1];
    Node* olkitail = linearize(ol);

    while(root->children.size() != 1){
        Node* sl = root->children[root->children.size() - 2];
        Node* slkitail = linearize(sl);

        Node* oh = root->children.back();
        root->children.pop_back();

        slkitail->children.push_back(oh);
    }
    return olkitail;
}

bool areSimilarStr(Node* root1, Node* root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }
    for(int i = 0; i < root1->children.size(); i++){
        Node* temp1 = root1->children[i];
        Node* temp2 = root2->children[i];
        bool rres = areSimilarStr(temp1, temp2);
        if(rres == false){
            return false;
        }
    }
    return true;
}

bool areMirrorStr(Node* root1, Node* root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }

    for(int i = 0; i < root1->children.size(); i++){
        Node* temp1 = root1->children[i];
        Node* temp2 = root2->children[root1->children.size() - 1 - i];
        if(areMirrorStr(temp1, temp2) == false){
            return false;
        }
    }
    return true;
}

bool isSymmetric(Node* root){
    return areMirrorStr(root, root);
}

/* DATE: 30th March 2019 */

void ceilAndFloor(Node* root, int &mn, int &mx, int &sz,
 int &ht, int &cl, int &fr, int depth, int k){
    
    sz++;
    ht = depth > ht? depth: ht;
    mn = root->data < mn? root->data: mn;
    mx = root->data > mx? root->data: mx;
    cl = root->data > k && root->data < cl? root->data : cl;
    fr = root->data < k && root->data > fr? root->data : fr;

    for(int i = 0; i < root->children.size(); i++){
        ceilAndFloor(root->children[i], mn, mx, sz, ht, cl, fr, depth + 1, k);
    }
}

void presPred(Node* root, int k, int& pd, int& ps, int &sta){
    // for preSuccesor, and Predesesor
    if(sta == 0){
        if(root->data != k){
            pd = root->data;
        } else{
            sta = 1;
        }
    } else if(sta == 1){
        ps = root->data;
        sta++;
    }


    for(int i = 0; i < root->children.size(); i++){
        presPred(root->children[i], k, pd, ps, sta);
    }

    // for postSuccesor, and Postdesesor
}

/*Date: 31st March 2019*/

void preSucc2(Node* root, int key, int& prev, int& curr, int& pred, int& succ){

    prev = curr;
    curr = root->data;

    if(curr == key){
        pred = prev;
    } else if(prev == key){
        succ = curr;
    }


    for(int i = 0; i < root->children.size(); i++){
        preSucc2(root->children[i], key, prev, curr, pred, succ);
    }
}

void floorforKthLargest(Node* root, int &fr, int &k){
    
    fr = root->data < k && root->data > fr? root->data : fr;

    for(int i = 0; i < root->children.size(); i++){
        floorforKthLargest(root->children[i], fr, k);
    }
}

int kthLargest(Node* root, int k){
    int fres = INT_MIN;
    int res = INT_MAX;
    for(int i = 0; i < k; i++){
        floorforKthLargest(root, fres, res);
        res = fres;
        //Alwasy remember to reset the state for next interation
        fres = INT_MIN;
    }
    return res;
}


void levelOrder(Node* root){
    
    list<Node*> queue;
    queue.push_back(root);
    
    while(queue.size() != 0){
        /* Get, Remove, Print, Add the Children */
        /*G.*/  Node* fr = queue.front();
        /*R*/   queue.pop_front();
        /*P*/   cout << fr->data << " ";
        /*AC*/  for(int i = 0; i < fr->children.size(); i++){
                    queue.push_back(fr->children[i]);
                }
    }
    cout << endl;

}

void levelOrderLineWise(Node* root){
    /* prevention from copy of next and curr we implement it like pointer*/
    list<Node*>* next = new list<Node*>();
    list<Node*>* curr = new list<Node*>();

    curr->push_back(root);

    while(curr->size() > 0){
        Node* fr = curr->front();
        curr->pop_front();
        cout << fr->data << " ";
        for(int i = 0; i< fr->children.size(); i++){
            next->push_back(fr->children[i]);
        }
        if(curr->size() == 0){
            delete curr;
            curr = next;
            next = new list<Node*>();
            cout << endl;
        }
    }

    delete curr;
    delete next;

}

void levelOrderLWzigzag(Node* root){
    list<Node*>* next = new list<Node*>();
    list<Node*>* curr = new list<Node*>();

    curr->push_back(root);
    bool l2r = true;

    while(curr->size() > 0){
        Node* fr = curr->front();
        curr->pop_front();
        cout << fr->data << " ";
        if(l2r){
            for(int i = 0; i< fr->children.size(); i++){
                next->push_front(fr->children[i]);
            }
        } else {
            for(int i = fr->children.size() - 1; i >= 0; i--){
                next->push_front(fr->children[i]);
            }
        }
        if(curr->size() == 0){
            delete curr;
            curr = next;
            next = new list<Node*>();
            cout << endl;
            l2r = !l2r;
        }
    }

    delete curr;
    delete next;
}

class Ehelper {
    public:
        Node* root;
        int state;
        Ehelper(Node* root, int state){
            this->root = root;
            this->state = state;
        }
};

void Euler(Node* root){
    list<Ehelper*> stack;

    Ehelper* rh = new Ehelper(root, 0);
    stack.push_front(rh);
    while(stack.size() > 0)
    {
        Ehelper* th = stack.front();
        int cs = th->root->children.size();

        if(th->state == 0)
        {
            cout << th->root->data << "PRE" << endl;
            th->state++;
        } 
        else if(th->state >= 1 && th->state <= cs)
        {
            Ehelper* ch = new Ehelper(th->root->children[th->state - 1], 0);
            stack.push_front(ch);
            if(th->state >= 2)
            {
                cout << th->root->data << "IN" << th->state - 1 << endl;
            }
            th->state++;
        } 
        else if(th->state == cs + 1)
        {
            cout << th->root->data << "POST" << endl;
            th->state++;
        } 
        else if(th->state == cs + 2)
        {
            stack.pop_front();
            delete th;
        }
        

    }

    cout << endl;
}

int main(){
    vector<int> dlist{
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    // Remove 11, -1 and get false result in areSimilarStr();
    vector<int> dlist2{
        1, 2, 5, -1, 6, -1, -1, 3, 7, -1, 8, /*11, -1,*/ 12, -1, -1, 9, -1, -1, 4, 10, -1, -1
    };


    Node* root = build(dlist);
    Node* root2 = build(dlist2);
    

/*    cout << "Size = ----" << size(root) << "------" << endl;
	
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
    display(root); */
    
    /* DATE: 28th March 2019 */
    cout << "-----------------" << endl;
//    linearize(root);
//    display(root);
   /* display(root2);
    cout << areSimilarStr(root, root2) << endl;
    cout << areMirrorStr(root,root2) << endl;*/
    /* DATE : 30th march 2019 */
    int mn = INT_MAX;
    int mx = INT_MIN;
    int sz = 0;
    int ht = 0;
    int cl = INT_MAX;
    int fr = INT_MIN;
    int k = 68;
    int pd = -1;
    int ps = -1;
    int sta = 0;
    ceilAndFloor(root, mn, mx, sz, ht, cl, fr, 0, k);
    // cout << mn << " " << mx << " " << sz << " " << ht << endl;
    // cout << cl << " " << fr << endl;
    presPred(root, 90, pd, ps, sta);
    // cout << pd << " " << ps << endl;
    
    /*Date: 31st March 2019*/
    int succ = -1;
    int pred = -1;
    int prev = -1;
    int curr = -1;
    preSucc2(root, 90, prev, curr, pred, succ);
    cout << pred << " " << succ << endl;
    
    cout << kthLargest(root, 10) << endl;

    levelOrder(root);
    // levelOrderLineWise(root);
    levelOrderLWzigzag(root);
    
    Euler(root);

    return 0;
}
