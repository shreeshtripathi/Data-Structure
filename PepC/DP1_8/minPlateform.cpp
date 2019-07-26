#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> arrival {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure {910, 1200, 1120, 1130, 1900, 2000};

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int left = 0;
    int right = 0;
    int platform = 0;
    int res = 0;
    while(left != arrival.size() && right != arrival.size())
    {
        if(arrival[left] < departure[right])
        {
            platform++;
            left++;
        }
        else
        {
            right++;
            platform--;
        }
        res = max(platform, res);
    }
    cout << res << endl;

    return 0;
}