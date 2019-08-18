#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void printkSmallestNum1(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    for(int i = 0; i < k; i++)
    {
        int val = pq.top();
        pq.pop();
        cout << val << " ";
    }
    cout << endl;
}

void printSmallestNum2(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i < arr.size(); i++){
        int val = pq.top();
        if(val > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    for(int i = 0; i < k; i++){
        int val = pq.top();
        pq.pop();
        cout << val << " ";
    }
    cout << endl;
}

void printKsortedArr(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k + 1; i < arr.size(); i++)
    {
        int val = pq.top();
        cout << val << " ";
        pq.pop();
        pq.push(arr[i]);
    }

    while(pq.size() > 0)
    {
        int val = pq.top();
        cout << val << " ";
        pq.pop();
    }
    cout << endl;
}

class MHelper
{
    public:
        int lindx;
        int valindx;
        int val;
        MHelper(int lindx, int valindx, int val)
        {
            this->lindx = lindx;
            this->valindx = valindx;
            this->val = val;
        }

        bool operator>(const MHelper& other) const
        {
            return this->val > other.val;
        }
};

void mergeKSortedList(vector<vector<int>>& list)
{
    priority_queue<MHelper, vector<MHelper>, greater<MHelper>> pq;

    for(int i = 0; i < list.size(); i++)
    {
        MHelper mh(i, 0, list[i][0]);
        pq.push(mh);
    }
    
    while(pq.size() > 0)
    {
        MHelper ch = pq.top();
        cout << ch.val << " ";
        pq.pop();
        if(ch.valindx < list[ch.lindx].size() - 1){
            MHelper hl(ch.lindx, ch.valindx + 1, list[ch.lindx][ch.valindx + 1]);
            pq.push(hl);
        }
    }
    cout << endl;
}

int main(int argv, char** argc)
{
    vector<int> arr {10, 15, 2, 17, 7, 18, 22, 9, 3};
    printkSmallestNum1(arr, 4);
    cout << "~~~~~~~~~~~~~~`" << endl;
    printSmallestNum2(arr, 4);

    vector<int> arr2 {7, 15, 5, 22, 18, 20, 27, 35, 40, 30};
    printKsortedArr(arr2, 2);
    cout << "~~~~~~~~~~~~~~" << endl;
    vector<vector<int>> list {
        {5, 15, 25, 35, 40},
        {11, 14, 22, 28},
        {2, 7, 17},
        {9, 12, 18, 24, 36}
    };
    mergeKSortedList(list);
}