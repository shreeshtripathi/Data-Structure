#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>* oa;
vector<int>* sa;

int sb;
int cb;

void preprocess()
{
    sb = sqrt(oa->size());
    cb = ceil(oa->size() * 1.0 /sb);
    sa = new vector<int> (cb, 0);
    for(int i = 0; i < oa->size(); i++)
    {
        // find index block
        int ib = i / sb; // i handle from 0-6, 7-13 etc.
        sa->at(ib) += oa->at(i);
    }
}

int query(int low, int hi)
{
    int sum = 0;
    
    //find index of block for low and high
    int ilb = low / sb;
    int ihb = hi / sb;

    if(ilb == ihb)
    {
        for(int i = low; i <= hi; i++){
            sum = sum + (*oa)[i];
        }
    }
    else
    {
        for(int i = low; i/sb == ilb; i++){
            sum = sum + (*oa)[i];
        }

        for(int i = ilb + 1; i <= ihb - 1; i++)
        {
            sum = sum + (*sa)[i]; 
        }

        for(int i = hi; i/sb == ihb; i--){
            sum = sum + (*oa)[i];
        }

    }

    return sum;
}

void update(int idx, int nval)
{
    int oval = (*oa)[idx];
    (*oa)[idx] = nval;
    int ib = idx / sb;
    (*sa)[ib] = (*sa)[ib] - oval + nval;
}

int queryTest(int low, int hi)
{
    int sum = 0;
    for(int i = low; i <= hi; i++){
        sum += (*oa)[i];
    }
    return sum;
}

int main(int argc, char **argv)
{
    oa = new vector<int>(55);
    for(int i = 0; i < oa->size(); i++){
        (*oa)[i] = rand() % 10;
    }
    preprocess();
    cout << query(15, 41) << "    " << queryTest(15, 41) << endl;
    cout << query(15, 25) << "    " << queryTest(15, 25) << endl;
    cout << query(15, 19) << "    " << queryTest(15, 19) << endl;

    update(18, 25);
    cout << query(15, 41) << "    " << queryTest(15, 41) << endl;
    cout << query(15, 25) << "    " << queryTest(15, 25) << endl;
    cout << query(15, 19) << "    " << queryTest(15, 19) << endl;
}