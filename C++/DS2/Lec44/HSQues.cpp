#include<iostream>

using namespace std;

int get(int a[], int b[], int as, int bs, int i)
{
    if(i < as){
        return a[i];
    }
    else
    {
        return b[i - as];
    }
    
}

void set(int a[], int b[], int as, int bs, int i, int val)
{
    if(i < as){
        a[i] = val;
    }
    else
    {
        b[i - as] = val;
    }
    
}

void swap(int a[], int b[], int as, int bs, int i, int j)
{
    int ith = get(a, b ,as, bs, i);
    int jth = get(a, b, as, bs, j);
    set(a, b, as, bs, i, jth);
    set(a, b, as, bs, j, ith);
}

void downheapify(int a[], int b[], int as, int bs, int idx, int sz)
{
    int maxidx = idx;
    int lci = 2 * idx + 1;
    int rci = 2 * idx + 2;

    if(lci < sz && get(a, b, as, bs, lci) > get(a, b, as, bs, maxidx))
    {
        maxidx = lci;
    }
        if( rci < sz && get(a, b, as, bs, rci) > get(a, b, as, bs, maxidx))
    {
        maxidx = rci;
    }
    
    if(maxidx != idx){
        swap(a, b, as, bs, maxidx, idx);
        downheapify(a, b, as, bs, maxidx, sz);
    }
}

void heapSort(int a[], int b[], int as, int bs)
{
    // make a priority queue of n elements
    for(int i = (as + bs) / 2 - 1; i >= 0; i--)
    {
        downheapify(a, b, as, bs, i, as + bs);
    }

    int cse = 0; // current sorted element
    while(cse < as+ bs - 1)
    {
        swap(a, b, as, bs, 0, as + bs -1 - cse);
        cse++;
        downheapify(a, b, as, bs, 0, as + bs - cse);
    }
}

int main(int argv, char** argc)
{
    int a[] = {5, 19, 3};
    int b[] = {0, 16, 12, 4, -4};
    heapSort(a, b, 3, 5);

    for(int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
    
}