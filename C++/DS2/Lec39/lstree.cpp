#include<iostream>
using namespace std;

int* ba = NULL;
int* sa = NULL;
int* lazy = NULL;
int s; // sizeof segment tree
int bas; // size of base array;

int getLog(int n)
{
    int log = 0;
    while((1 << log) < n){
        log++;
    }
    return log;
}

void build(int ss, int se, int si)
{
    if(ss == se){
        sa[si] = ba[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build(ss, mid, 2 * si + 1);
    build(mid + 1, se, 2 * si + 2);
    sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
}

void preprocess()
{
    int h = getLog(bas) + 1;
    s = (1 << h) - 1;
    sa = new int[s];
    lazy = new int[s];
    build(0, bas-1, 0);
}

void handlePendingUpdates(int si, int ss, int se)
{
    sa[si] += (se - ss + 1) * lazy[si];
    if(ss != se){
        lazy[2 * si + 1] += lazy[si];
        lazy[2 * si + 2] += lazy[si];
    }
    lazy[si]=0;
}

void update(int delta, int qs, int qe, int ss, int se, int si)
{
    handlePendingUpdates(si, ss, se);
    if(ss >= qs && se <= qe)
    {
        //completely inside query
        lazy[si] = delta;
        handlePendingUpdates(si, ss, se);
    }
    else if(qs > se || qe < ss)
    {
        // outside the segment
        return;
    }
    else
    {
        int mid = (ss + se) / 2;
        update(delta, qs, qe, ss, mid, 2 * si + 1);
        update(delta, qs, qe, mid + 1, se, 2 * si + 2);
        sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
    }
}

int query(int qs, int qe, int ss, int se, int si)
{
    handlePendingUpdates(si, ss, se);
    if(ss >= qs && se <= qe)
    {
        //completely inside query
        return sa[si];
    }
    else if(qs > se || qe < ss)
    {
        // outside the segment
        return 0;
    }
    else
    {
        int mid = (ss + se) / 2;
        int lc = query(qs, qe, ss, mid, 2 * si + 1);
        int rc = query(qs, qe, mid + 1, se, 2 * si + 2);
        return lc + rc;
    }
}

void display()
{
    for(int i = 0; i < s; i++)
    {
        cout << sa[i] << " ";
    }
    cout << endl;
}

int main(int argv, char** argc)
{
    ba = new int[7]{2, 5, 3, 1, 7, 4, 9};
    bas = 7;
    preprocess();
    // display();
    int q1 = query(2, 5, 0, bas - 1, 0);
    int q2 = query(3, 6, 0, bas - 1, 0);
    cout << q1 << " " << q2 << endl;

    // display();
    
    update(2, 0, 6, 0, bas - 1, 0);

    q1 = query(2, 5, 0, bas - 1, 0);
    q2 = query(3, 6, 0, bas - 1, 0);
    cout << q1 << " " << q2 << endl;

    // display();
}