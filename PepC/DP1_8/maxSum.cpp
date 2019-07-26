#include<iostream>
#include<vector>

using namespace std;

int maxSum(vector<int>& vec)
{
    int incl = vec[0];
    int excl = 0;

    for(int i = 1; i < vec.size(); i++)
    {
        int temp = excl;
        excl = max(incl, excl);
        incl = temp + vec[i];
    }
    return max(incl, excl);
}

int main(int agvr, char**c)
{
    vector<int> vec{5, 6, 10, 100, 10};
    cout << maxSum(vec) << endl;
    return 0;
}