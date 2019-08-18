#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
#include<climits>

using namespace std;

void highestFreqChar(string& str)
{
    unordered_map<char, int> fqmap;
    for(int i = 0; i < str.length(); i++)
    {
        if(fqmap.count(str[i]) == 0)
        {
            fqmap[str[i]] = 1;
        }
        else
        {
            fqmap[str[i]]++;
        }
    }
    char hfc;
    for(auto itr = fqmap.begin(); itr != fqmap.end(); itr++)
    {
        if(itr->second > fqmap[hfc]){
            hfc = itr->first;
        }
    }
    cout << "Highest frequency character is : " << hfc << endl; 
}

void getCommonElement1(vector<int>& one, vector<int>& two)
{
    unordered_map<int, int> fqmap;
    for(int i = 0; i < one.size(); i++)
    {
        // fqmap[one[i]]++; we can do it in this way too
        fqmap[one[i]] = fqmap.count(one[i]) == 0 ? 1 : fqmap[one[i]] + 1;
    }

    for(int i = 0; i < two.size(); i++)
    {
        if(fqmap.count(two[i]) != 0)
        {
            cout << two[i] <<  " ";
            fqmap.erase(two[i]);
        }
    }
    cout << endl;
}

void getCommonElement2(vector<int>& one, vector<int>& two)
{
    unordered_map<int, int> fqmap;
    for(int i = 0; i < one.size(); i++)
    {
        // fqmap[one[i]]++; we can do it in this way too
        fqmap[one[i]] = fqmap.count(one[i]) == 0? 1: fqmap[one[i]] + 1;
    }

    for(int i = 0; i < two.size(); i++)
    {
        if(fqmap.count(two[i]) != 0 && fqmap[two[i]] > 0)
        {
            cout << two[i] <<  " ";
            fqmap[two[i]]--;
        }
    }
    cout << endl;
}

void largestConsecutiveSequence(vector<int>& arr)
{
    unordered_map<int, bool> mp;
    for(int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = true;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(mp.count(mp[arr[i]] - 1) != 0)
        {
            mp[arr[i]] = false;
        }
    }

    int sp;
    int len = INT_MIN;
    for(int i = 0; i < arr.size() ; i++)
    {
        if(mp[arr[i]] == true)
        {
            int tsp = arr[i];
            int tspl = 0;
            while(mp.count(tsp + tspl) != 0)
            {
                tspl++;
            }

            if(tspl > len)
            {
                len = tspl;
                sp = tsp;
            }
        }
    }
    cout << sp << " and have length " << len << endl;
}
 /*
class AHepler
{
    public:
        int si;
        int ei;
        int len;
        AHepler(int si, int ei, int len)
        {
            this->si = si;
            this->ei = ei;
            this->len = len;
        }
};

void maxSubArray(vector<int>& arr, int k)
{
    unordered_map<int, AHepler> hm;
    for(int i = 1; i < k; i++)
    {
        AHepler ch(-1, -1, 0);
        hm[i] = ch;
    }

    int cs = 0;
    AHepler hlp(0, -1, 0);
    hm[0] = hlp;
    for(int i = 0; i < arr.size(); i++)
    {
        cs += arr[i];
        int mod = cs / k;
        AHepler ch = hm[mod];
        if(ch.si == -1)
        {
            ch.si = i + 1;
        }
        else {
            ch.len++;
            ch.ei = i;
        }
        hm[mod] = ch;
    }

    AHepler th(-1, -1, -1);
    for(auto itr = hm.begin(); itr != hm.end(); itr++)
    {
        if(th.len < itr->second.len)
        {
            th.len = itr->second.len;
            th.si = itr->second.si;
            th.ei = itr->second.ei;
        }
    }

    cout << th.si << " " << th.ei << " @ length " << th.len << endl; 



}
*/

void maxSubArray(vector<int>& arr, int k)
{
    vector<int> psa; // prefix sum array
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        psa.push_back(sum % k);
    }
    unordered_map<int, pair<int, int>> map;
    for(int i = 0; i < k; i++)
    {
        map[i].first=-1;
        map[i].second=-1;
    }

    int osp=-1;
    int oep=-2;

    for(int i=0;i<psa.size();i++) {
        if(map[psa[i]].first == -1) {
            map[psa[i]].first=i+1;
        }
        else {
            map[psa[i]].second=i;
        }
        if(map[psa[i]].second - map[psa[i]].first > oep-osp) {
            osp=map[psa[i]].first;
            oep=map[psa[i]].second;
        }
    }
    cout<<osp<<","<<oep<<endl;
}

int main(int argv, char** argc)
{
    string str = "shreeesh";
    highestFreqChar(str);
    vector<int> one {5, 1, 3, 2, 2, 1, 2};
    vector<int> two {1, 4, 1, 2, 2, 1, 5};
    getCommonElement1(one, two);
    getCommonElement2(one, two);

    vector<int> arr {2,12,9,16,10,5,3,20,25,11,1,8,6};
    largestConsecutiveSequence(arr);
    cout << "~~~~~~~~~~~" << endl;
    vector<int> arr1{12,5,7,15,3,6,11,2,9,8,-1,7};
    maxSubArray(arr1, 5);


} 