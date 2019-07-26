#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void maxPrice(vector<int>& price, int len)
{
    vector<int> strg(len + 1, 0);
    
    for(int s = 1; s <= len; s++)
    {
        for(int i = 0; i <= price.size(); i++)
        {  
            if(s >= i)
            {
                strg[s] = max(strg[s - i] + price[i], strg[s]);
            }
        }
    }

    for(int i = 0; i < strg.size(); i++)
    {
        cout << strg[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    vector<int> price {0, 3, 5, 6, 15, 10, 25, 12, 24};
    int length = 8;
    maxPrice(price, length);
}