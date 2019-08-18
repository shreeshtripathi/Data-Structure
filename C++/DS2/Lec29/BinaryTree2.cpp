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

//Date : 4th April 2019

bool find(Node* root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    bool rres = find(root->left, data);
    if(rres){
        return true;
    }
    rres = find(root->right, data);
    return rres;
}

vector<int>* n2rp(Node* root, int data){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
        vector<int>* bres = new vector<int>();
        bres->push_back(root->data);
        return bres;
    }

    vector<int>* n2rpath1 = n2rp(root->left, data);
    
    if(n2rpath1 != NULL){
        n2rpath1->push_back(root->data);
        return n2rpath1;
    }
    
    vector<int>* n2rpath2 = n2rp(root->right, data);
    
    if(n2rpath2 != NULL){
        n2rpath2->push_back(root->data);
        return n2rpath2;
    }
}

vector<Node*>* n2rp2(Node* root, int data){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
        vector<Node*>* bres = new vector<Node*>();
        bres->push_back(root);
        return bres;
    }

    vector<Node*>* n2rpath1 = n2rp2(root->left, data);
    
    if(n2rpath1 != NULL){
        n2rpath1->push_back(root);
        return n2rpath1;
    }
    
    vector<Node*>* n2rpath2 = n2rp2(root->right, data);
    
    if(n2rpath2 != NULL){
        n2rpath2->push_back(root);
        return n2rpath2;
    }
}


void kdown(Node* root, Node* phb, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
    }
    kdown(root->left, phb, k - 1);
    kdown(root->right, phb, k - 1);
}

void kfar(Node* root, int k, int data){
    vector<Node*>* n2rp = n2rp2(root, data);
    for(int i = 0; i <= k && i < n2rp->size(); i++){
        if(i == 0){
            kdown(n2rp->at(i), NULL, k - i);
        } else {
            kdown(n2rp->at(i), n2rp->at(i - 1), k - i);
        }
    }
}


//this doesnot work because we have danfling pointer remoain same
void removeLeaf1(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL; 
    }
    
    removeLeaf1(root->left);
    removeLeaf1(root->right);
}


//remove Leaf2 doesnot cover the case if only root is here;
void removeLeaf2(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
        Node* temp = root->left;
        root->left = NULL; 
        delete temp;
    }
    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL){
        Node* temp = root->right;
        root->right = NULL; 
        delete temp;
    }

    removeLeaf2(root->left);
    removeLeaf2(root->right);
}
//this handle every case;
Node* removeLeaf3(Node* root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    root->left = removeLeaf3(root->left);
    root->right = removeLeaf3(root->right);
}

//psc = print single child

void psc(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right != NULL){
        cout << root->right->data << " ";
    }
    if(root->left != NULL && root->right ==NULL){
        cout << root->left->data << " ";
    }
    psc(root->left);
    psc(root->right);
}

//pir = print root to leaf path in range of root to leaf path in low and high
void pir(Node* root, int low, int high, int cs, vector<int> cnt){
    
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        cnt.push_back(root->data);
        cs += root->data;
        if(cs > low && cs < high){
            for(int i = 0; i < cnt.size(); i++){
                cout << cnt[i] << "-->";
            }
            cout << endl;
        }
        return;
    }
    cnt.push_back(root->data);
    cs += root->data;
    pir(root->left, low, high, cs, cnt);
    pir(root->right, low, high, cs, cnt); 

}

int main(){
    vector<int> dlist = {50, 25, 12, -1, 37, 30, -1, 40, -1,
            -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node* root = construct(dlist);
    /*
    display(root);
    cout << size(root) << endl;
    cout << mymax(root) << endl;
    cout << sum(root) << endl;
    cout << height(root) << endl;
    */

   /*Date: 4th April 2019*/


    cout << find(root, 90) << endl;

    vector<int>* n2r = n2rp(root, 40);
    for(int i = 0; i < n2r->size(); i++){
        cout << (*n2r)[i] << "-->";
    }
    cout << endl;
   
   kdown(root, NULL, 2);
   cout << endl;

    vector<int> list1 {
        1, 2, 4, -1, 5, 6, 8, 20, 22, -1, -1, 21, -1, -1, 9, 12, 14, -1, 15, 18, -1, 19, -1, -1, -1, 13, -1, -1, -1, 7, 10, -1, 11, 16, -1, 17, -1, -1, -1, -1, -1, 3, -1, -1
    };
    Node* nr = construct(list1);
    kfar(nr, 3, 9);
    cout << endl;
    cout << "----------\n";
    //removeLeaf2(root);
    psc(nr);
    cout << endl;
    display(root);
    vector<int> vec;
    pir(root, 152, 257, 0, vec);
    return 0;
}