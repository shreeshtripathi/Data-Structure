#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

void slidingWindow(vector<int>& arr, int k)
{
    //Make next greater element
    stack<int> stk;
    vector<int> nge(arr.size(), 0);
    stk.push(arr.size() - 1);
    nge[arr.size() - 1] = arr.size();
    
    for(int i = arr.size() - 2; i >= 0; i--)
    {
        while(stk.size() > 0 && arr[stk.top()] < arr[i])
        {
            stk.pop();
        }
        nge[i] = stk.size() > 0? stk.top(): arr.size(); 
        stk.push(i);
    }

    for(int i = 0; i < nge.size(); i++)
    {
        cout << nge[i] << " ";
    }
    cout << endl;

    // Calculation of sliding window array using lge

    vector<int> res(arr.size() - k + 1);
    int j = 0;
    for(int i = 0; i < arr.size() - k + 1; i++)
    {
        if(j < i)
        j = i;

        while(nge[j] < i + k)
        {
            j = nge[j];
        }

        res[i] = arr[j];
    }
     
    // printing of answer
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

}

int main(int argc, char** argv)
{
    vector<int> ques{3, 9, 1, 4, 2 ,7, 5, 10, 6, 8};
    int k = 5;
    slidingWindow(ques, k);
}