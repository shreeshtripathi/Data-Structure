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


//this doesnot work because we have dangling pointer remain same
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
void pir(Node* root, int low, int high, int cs, vector<int> &cnt){
    
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
    cnt.pop_back();

}

/* Date: 6th April 2019*/

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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

Node* construct2(vector<int> &post, vector<int> &in, int postart, int poend, int instart, int inend){
    if(postart > poend || instart > inend){
        return NULL;
    }
    Node* root = new Node(post[poend]);
    int lhs = 0;
    for(int i = instart; i <= inend; i++){
        if(in[i] == post[poend]){
            break;
        } else{
            lhs++;
        }
    }
    
    root->left = construct2(post, in, postart, postart + lhs - 1, instart, instart + lhs - 1);
    root->right = construct2(post, in, postart + lhs, poend - 1, instart + lhs + 1, inend);
    return root;
}

Node* construct3(vector<int> &pre, vector<int> &post, int prestart, int prend, int postart, int poend){
    if(prestart > prend){
        return NULL;
    }
    if(prestart == prend){
        Node* root = new Node(pre[prestart]);
        return root;
    }
    Node* root = new Node(pre[prestart]);
    int lhs = 1;
    for(int i = postart; i <= poend -1; i++){
        if(post[i] == pre[prestart + 1]){
            break;
        }
        else{
            lhs++;
        }
    }

    root->left = construct3(pre, post, prestart + 1, prestart + lhs, postart, postart + lhs - 1);
    root->right = construct3(pre, post, prestart + lhs + 1, prend, postart + lhs, poend - 1);
    return root;
}

Node* construct4(vector<int> &darray, vector<int> &parray){
    Node* narr[101] = {NULL};
    Node* root = NULL;

    //Create node of data array
    for(int i = 0; i < darray.size(); i++){
        narr[darray[i]] = new Node(darray[i]);
    }

    for(int i = 0; i < darray.size(); i++){
        if(parray[i] == -1){
            //Node* cnode = new Node();
            root = narr[darray[i]];
        }
        else{
            Node* n = narr[darray[i]];
            Node* parent = narr[parray[i]];

            if(parent->left == NULL){
                parent->left = n;
            } else{
                parent->right = n;
            }

        }
    }


    return root;
}

// Diameter in O(n^2)
int diameter1(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter1(root->left);
    int rd = diameter1(root->right);

    int f1 = lh + rh + 1;
    int f2 = ld;
    int f3 = rd;

    return max(f1, max(f2, f3));
}

//Diameter in O(n)
class DiaPair{
    public:
    int d = 0; // Height
    int h = 0; // diameter
};

DiaPair* diameter2(Node* root){
    if(root == NULL){
        DiaPair* bp = new DiaPair();
        bp->h = 0;
        bp->d = 0;
        return bp;
    }

    DiaPair* lp = diameter2(root->left);
    DiaPair* rp = diameter2(root->right);

    DiaPair* mp = new DiaPair();
    mp->d = max(lp->h + rp->h + 1, max(lp->d, rp->d));
    mp->h = max(lp->h, rp->h) + 1;
    delete lp;
    delete rp;
    return mp;

}

/* DATE: 7th April 2019*/

class balancePair{
    public:
    int ht = 0;
    bool balance = true;
};

balancePair* isBalaced(Node* root){
    if(root == NULL){
        balancePair* bpair = new balancePair();
        bpair->balance = true;
        bpair->ht = 0;
        return bpair;
    }
    
    balancePair* lp = isBalaced(root->left);
    balancePair* rp = isBalaced(root->right);

    balancePair* myPair = new balancePair();
    myPair->balance = lp->balance && rp->balance && abs(lp->ht - rp->ht) < 1;
    myPair->ht = max(lp->ht, rp->ht) + 1;
    delete lp;
    delete rp;
    return myPair;
}

class BSTPair{
    public:
    bool isBST = true;
    int min = INT_MAX;
    int max = INT_MIN;

    int LBSTsize = 0;
    Node* root = NULL;

};

BSTPair* isBST(Node* root){
    if(root == NULL){
        BSTPair* bp = new BSTPair();
        return bp;
    }
    BSTPair* lp = isBST(root->left);
    BSTPair* rp = isBST(root->right);
    
    BSTPair* mp = new BSTPair();
    mp->isBST = lp->isBST &&
                rp->isBST &&
                root->data > lp->max &&
                root->data < rp->min;

    mp->min = min(root->data, min(lp->min, rp->min));
    mp->max = max(root->data, max(lp->max, rp->max));
    delete lp;
    delete rp;
    return mp;

}

BSTPair* LBST(Node* root){
    if(root == NULL){
        BSTPair* bp = new BSTPair();
        return bp;
    }
    BSTPair* lp = LBST(root->left);
    BSTPair* rp = LBST(root->right);
    
    BSTPair* mp = new BSTPair();
    mp->isBST = lp->isBST &&
                rp->isBST &&
                root->data > lp->max &&
                root->data < rp->min;
    mp->min = min(root->data, min(lp->min, rp->min));
    mp->max = max(root->data, max(lp->max, rp->max));

    if(mp->isBST == true){
        mp->root = root;
        mp->LBSTsize = lp->LBSTsize + rp->LBSTsize + 1;
    } else {
        if(lp->LBSTsize > rp->LBSTsize){
            mp->root = lp->root;
            mp->LBSTsize = lp->LBSTsize;
        } else{
            mp->root = rp->root;
            mp->LBSTsize = rp->LBSTsize;
        }
    }
    delete lp;
    delete rp;
    return mp;

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
    /*
    
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
    display(root); */
    vector<int> vec;
    pir(root, 152, 257, 0, vec);
    

   /* Date: 6th April 2019*/

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;

    vector<int> pre = {10, 20, 40, 80, 90, 50, 30, 60, 70, 100, 110};
    vector<int> post = {80, 90, 40, 50, 20, 60, 100, 110, 70, 30, 10};
    vector<int> inO = {80, 40, 90, 20, 50, 10, 60, 30, 100, 70, 110};
    vector<int> lorder = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    cout << "-----------------" << endl;

    // Node* ntree = construct1(pre, inO, 0, pre.size() - 1, 0, inO.size() - 1);
    // Node* ntree2 = construct2(post, inO, 0, post.size() - 1, 0, inO.size() - 1);
    // Node* ntree3 = construct3(pre, post, 0, pre.size() - 1, 0, post.size() - 1);

    vector<int> darray = {30, 40, 37, 12, 25, 75, 62, 87, 50};
    vector<int> parray = {37, 37, 25, 25, 50, 50, 75, 75, -1};
    Node* ntree4 = construct4(darray, parray); 
    cout << diameter1(ntree4) << endl;
    DiaPair* dia = diameter2(ntree4);
    cout << dia->d << endl;

    /* DATE: 7th April 2019*/

    cout << "-----7th April 2019-----" << endl;

/*    vector<int> balTree = {10,20,40,-1,-1,30,50,60,-1-1,-1,-1};
    Node* bal = construct(balTree);
    display(bal);
    balancePair* Balance = isBalaced(bal);
    cout << Balance->balance << endl; */

/*    vector<int> bstTree = {50,25,12,-1,37,30,-1,49,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
    Node* bst = construct(bstTree);
    // display(bst);
    BSTPair* BST = isBST(bst);
    cout << BST->isBST << endl;
    */

    vector<int> inBST = {10,12,16,20,22,25,24,37,40,50,62,70,75,87};
    vector<int> preBST = {50,25,12,10,20,16,22,37,24,40,75,62,70,87};
    Node* lBST = construct1(preBST, inBST, 0, preBST.size() - 1, 0, inBST.size() - 1);
    //display(lBST);
    BSTPair* Lbst = LBST(lBST);
    display(Lbst->root);
    // cout << Lbst->root->data << endl;
    cout << Lbst->LBSTsize << endl;
    return 0;
}