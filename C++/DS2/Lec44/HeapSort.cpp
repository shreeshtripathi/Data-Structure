#include<iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void downheapify(int arr[], int idx, int sz)
{
    int maxidx = idx;
    int lci = 2 * idx + 1;
    int rci = 2 * idx + 2;

    if(lci < sz && arr[lci] > arr[maxidx])
    {
        maxidx = lci;
    }
    if( rci < sz && arr[rci] > arr[maxidx])
    {
        maxidx = rci;
    }
    
    if(maxidx != idx){
        swap(arr, maxidx, idx);
        downheapify(arr, maxidx, sz);
    }
}

void heapSort(int arr[], int n)
{
    // make a priority queue of n elements
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        downheapify(arr, i, n);
    }

    int cse = 0; // current sorted element
    while(cse < n - 1)
    {
        swap(arr, 0, n -1 - cse);
        cse++;
        downheapify(arr, 0, n - cse);
    }
}

int main(int argv, char** argc)
{
    int arr[] = {9, 8, 7, 6, 6, 10, 15, 5, 4, 3, 2 , 1};
    heapSort(arr, 12);

    for(int i = 0; i < 12; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}