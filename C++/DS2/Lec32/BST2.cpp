#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void display(Node* root){
    if(root == NULL){
        return;
    }


    if(root->left == NULL){
        cout << " . <-- " ;
    } else{
        cout << root->left->data << " <-- ";
    }
    cout << root->data;
    if(root->right == NULL){
        cout << " --> . " ;
    } else{
        cout << " --> " <<root->right->data;
    }
    cout << endl;


    display(root->left);
    display(root->right);

}

Node* construct(vector<int> arr, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    int mid = (lo + hi) / 2;
    Node* root = new Node(arr[mid]);
    root->left = construct(arr, lo, mid - 1);
    root->right = construct(arr, mid + 1, hi);
    return root;
}

int myMin(Node* root){
    if(root->left == NULL){
        return root->data;
    }
    else
    {
        return myMin(root->left);
    }
}

int myMax(Node* root){
    
    if(root->right == NULL){
        return root->data;
    }
    else
    {
        return myMax(root->right);
    }
}

bool find(Node* root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data)
    {
        return true;
    }
    else if(root->data > data)
    {
        return find(root->left, data);
    } 
    else
    {
        return find(root->right, data);
    }
}

Node* construct1(vector<int> &pre, vector<int> &in, int preStart, int prend, int instart, int inend){
    if(preStart > prend || instart > inend){
        return NULL;
    }
    
    Node* root = new Node(pre[preStart]);
    int lhs = 0;
    for(int i = instart; i <= inend; i++){
        if(in[i] == pre[preStart]){
            break;
        }
        else{
            lhs++;
        }
    }
    root->left = construct1(pre, in, preStart + 1, preStart + lhs, instart, instart + lhs - 1);
    root->right = construct1(pre, in, preStart + lhs + 1, prend, instart + lhs + 1, inend);
    return root;
}

 //ptsp = print target sum pair
void ptsp1(Node* oroot, Node* root, int target){
    if(root == NULL){
        return;
    }
    int n2f= target - root->data;
    if(root->data < n2f){
        bool found = find(oroot, n2f);
        if(found == true){
            cout << root->data << " , " << n2f << endl;
        }
    }
    ptsp1(oroot, root->left, target);
    ptsp1(oroot, root->right, target);
}

void filler(Node* root, vector<int>& data){
    if(root == NULL){
        return;
    }

    filler(root->left, data);
    data.push_back(root->data);
    filler(root->right, data);
}

void ptsp2(Node* root, int target){
    // make a vector and fill it in IN-AREA of BST
    vector<int> data;
    filler(root, data);
    
    int le = 0;
    int ri = data.size() - 1;
    while(le < ri){
        int sum = data[le] + data[ri];
        if(sum > target){
            ri--;
        } else if(sum < target){
            le++;
        } else{
            cout << data[le] << " , " << data[ri] << endl;
            le++;
            ri--;
        }
    }
}

class Ehelper{
    public:
        Node* node;
        int state = 0;
        Ehelper(Node* node){
            this->node = node;
        }
};

Node* Euler(vector<Ehelper*>& stack){
    // vector<Ehelper*> stack;
    // Ehelper* rh = new Ehelper(root);
    // stack.push_back(rh);

    while(stack.size() > 0){
        Ehelper* th = stack.back();
        if(th->state == 0)
        {
            // cout << th->node->data << " PRE" << endl;
            if(th->node->left != NULL){
                stack.push_back(new Ehelper(th->node->left));
            }
            th->state++;
        } 
        else if(th->state == 1)
        {
            // cout << th->node->data << " IN" << endl;
            if(th->node->right != NULL){
                stack.push_back(new Ehelper(th->node->right));
            }
            th->state++;
            return th->node;
        }
        else if(th->state == 2)
        {
            // cout << th->node->data << " POST" << endl;
            stack.pop_back();
            th->state++;
        }
    }
    return NULL;
}

Node* RevEuler(vector<Ehelper*>& stack){
    // vector<Ehelper*> stack;
    // Ehelper* rh = new Ehelper(root);
    // stack.push_back(rh);

    while(stack.size() > 0){
        Ehelper* th = stack.back();
        if(th->state == 0)
        {
            // cout << th->node->data << " PRE" << endl;
            if(th->node->right != NULL){
                stack.push_back(new Ehelper(th->node->right));
            }
            th->state++;
        } 
        else if(th->state == 1)
        {
            // cout << th->node->data << " IN" << endl;
            if(th->node->left != NULL){
                stack.push_back(new Ehelper(th->node->left));
            }
            th->state++;
            return th->node;
        }
        else if(th->state == 2)
        {
            // cout << th->node->data << " POST" << endl;
            stack.pop_back();
            th->state++;
        }
    }
    return NULL;
}

//make euler and reuler
void ptsp3(Node* root, int target){
    vector<Ehelper*> ls;
    vector<Ehelper*> rs;
    ls.push_back(new Ehelper(root));
    rs.push_back(new Ehelper(root));
    Node* le = Euler(ls);
    Node* ri = RevEuler(rs);
    while(le->data < ri->data){
        int sum = le->data + ri ->data;
        if(sum < target)
        {
            le = Euler(ls);
        }
        else if(sum > target)
        {
            ri = RevEuler(rs);
        }
        else
        {
            cout << le->data << " , " << ri->data << endl;
            le = Euler(ls);
            ri = RevEuler(rs);
        }
        
    }

}
class RplcHelp
{
    public:
        int sum = 0;
};
//replace with sum of large
int sum = 0;
void rwsol(Node* root){
    if(root == NULL){
        return;
    }
    rwsol(root->right);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    rwsol(root->left);
    
}

/*Date : 9th April 2019*/

Node* add(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = add(root->left, data);
    } else if(root->data < data){
        root->right = add(root->right, data);
    }

    return root;
    
}

Node* remove(Node* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data > data){
        root->left = remove(root->left, data);
    } else if(root->data < data){
        root->right = remove(root->right, data);
    } else if(root->data == data){
        if(root->left != NULL && root->right != NULL){
            int num = myMax(root->left);
            root->data = num;
            root->left = remove(root->left, num);
        } else {
            Node* temp = root;
            root = root->left != NULL? root->left : root->right;
            delete temp;
        }
    }
    return root;
}

int countBST(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        c += countBST(i) * countBST(n-i-1);
    }
    return c;
}

int main(){
    /* DATE: 7th April 2019 */
    vector<int> arr = {20,30,40,50,60,70,80};
    Node* root = construct(arr, 0, arr.size() - 1);
    display(root);
    cout << myMax(root) << endl;
    cout << myMin(root) << endl;
    cout << find(root, 100) << endl;
    ptsp1(root, root, 100);
    cout << "------------" << endl;
    // ptsp2(root, 100);
    display(root);
    cout << "------------" << endl;
    // rwsol(root);
    //display(root);
    //ptsp3(root, 100);
    cout << "----- 9th April 2019 -------" << endl;
    root = add(root, 10);
    display(root);
    cout <<"----------" << endl;
    root = remove(root, 30);
    display(root);
    cout << countBST(2) << endl;
    return 0;
}
