// code - count the sub sequence of abc of order a^ib^jc^k

#include<iostream>
#include<vector>

using namespace std;

void countaibjck(string str)
{
    int counta = 0;
    int countb = 0;
    int countc = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'a')
            counta = 2 * counta + 1;
        else if(str[i] == 'b')
            countb = 2 * countb + counta;
        else 
            countc = 2 * countc + countb;
    }

    cout << countc << endl;

}

int main(int argc, char** argv)
{
    countaibjck("abcabc");
}