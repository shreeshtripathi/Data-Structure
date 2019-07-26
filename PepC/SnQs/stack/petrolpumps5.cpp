#include<iostream>
#include<vector>

using namespace std;

int petrolPumps(vector<int>& o, vector<int>& d)
{
    int i = 0;
    int j = 0;
    
    int spare = 0;

    while(true)
    {
        if(spare + o[j] >= d[j])
        {
            spare = spare + o[j] - d[j];
            j = (j + 1) % o.size();
            if(j == i)
            {
                return j;
            }
        }
        else
        {
            if(j < i)
            {
                return -1;
            }
            else
            {
                spare = 0;
                i = (j + 1)%o.size();
                j = i;
            }
        }
    }
}

int main(int argc, char** argv)
{
    vector<int> o{6, 4, 8, 2, 3, 3, 1, 7, 1};
    vector<int> d{5, 5, 2, 4, 4, 6, 2, 7, 1};

    cout << petrolPumps(o, d) << endl;
}