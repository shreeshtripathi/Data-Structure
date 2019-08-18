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

Node* construct(vector<int> dlist){
    Node* root = NULL;
    vector<Node*> nlist;
    for(int i = 0; i < dlist.size(); i++){
        if(dlist[i] == -1){
            nlist.pop_back();
        }
        else {
            Node* nn = new Node(dlist[i]);
            if(nlist.size() == 0){
                root = nn;
            }
            else{
                Node* ln = nlist.back();
                if(ln->left == NULL){
                    ln->left = nn;
                } else {
                    ln->right = nn;
                }
            }
            nlist.push_back(nn);
        }
    }
    return root;
}

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

int size(Node* root){
    if(root == NULL){
        return 0;
    }

    int ls = size(root->left);
    int rs = size(root->right);
    return ls + rs + 1;
}

int mymax(Node* root){
    if(root == NULL){
        return INT_MIN;
    }

    int lm = mymax(root->left);
    int rm = mymax(root->right);
    int rres = max(lm, root->data);
    rres = max(rres, rm);
    return rres;
}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int s = root->data;
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    return s + lsum + rsum;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}


int main(){
    vector<int> dlist = {50, 25, 12, -1, 37, 30, -1, 40, -1,
            -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node* root = construct(dlist);

    display(root);
    cout << size(root) << endl;
    cout << mymax(root) << endl;
    cout << sum(root) << endl;
    cout << height(root) << endl;
    return 0;
}