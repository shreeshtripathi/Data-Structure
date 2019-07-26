// count binary string of length 'n' which donot contain consecutive 0's
#include<iostream>
#include<vector>

using namespace std;

void countzo(int n)
{
    int zeros = 1;  // number of binary num having length 0 and ending with 0
    int ones = 1;   // "

    for(int i = 2; i < n; i++)
    {
        int newzeros = ones;
        int newones = zeros + ones;

        ones = newones;
        zeros = newzeros;
    }
    cout << ones + zeros << endl;
}


int main(int argc, char** argv)
{
    countzo(5);
}