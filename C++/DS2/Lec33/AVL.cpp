#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int ht;
        int bal;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->ht = 1;
            this->bal = 0;
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
    cout << root->data << " [" << root->ht << "," << root->bal << "] ";
    if(root->right == NULL){
        cout << " --> . " ;
    } else{
        cout << " --> " <<root->right->data;
    }
    cout << endl;


    display(root->left);
    display(root->right);

}

// set height and balace
void sethnb(Node* root){
    int lh = root->left == NULL? 0 : root->left->ht;
    int rh = root->right == NULL? 0 : root->right->ht;
    root->ht = max(lh,rh) + 1;
    root->bal = lh - rh;
}

Node* rotateRight(Node* z){
    Node* y = z->left;
    Node* t2 = y->right;
    y->right = z;
    z->left = t2;

    sethnb(z);
    sethnb(y);

    return y;
}

Node* rotateLeft(Node* z){
    Node* y = z->right;
    Node* t2 = y->left;
    y->left = z;
    z->right = t2;

    sethnb(z);
    sethnb(y);

    return y;
}

Node* handleBalance(Node* root){
    if(root->bal == 2 && root->left->bal == 1){//LL problem
        root = rotateRight(root);
    } 
    else if(root->bal == 2 && root->left->bal == -1){//LR problem
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    } 
    else if(root->bal == -2 && root->right->bal == -1){ //RR problem
        root = rotateLeft(root);
    }
    else if(root->bal == -2 && root->right->bal == 1){ //RL problem
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

Node* construct(vector<int> arr, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    int mid = (lo + hi) / 2;
    Node* root = new Node(arr[mid]);
    root->left = construct(arr, lo, mid - 1);
    root->right = construct(arr, mid + 1, hi);
    sethnb(root);
    return root;
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

    sethnb(root);
    root = handleBalance(root);

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
    if(root != NULL){
        
    }
    return root;
}

int main(){
    vector<int> list {12, 25, 37, 50, 62, 75, 87};
    Node* root = construct(list, 0, list.size() - 1);
    cout << "-------------" << endl;
    add(root, 10);
    add(root, 5);
    display(root);
    cout << "-------------" << endl;
    add(root, 15);
    display(root);
    return 0;
}
