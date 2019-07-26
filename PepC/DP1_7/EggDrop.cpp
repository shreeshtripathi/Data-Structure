#include<iostream>
#include<vector>
#include<string>

using namespace std;

int eggDrop(int floor, int eggs, vector<vector<int>>& qb)
{
    if(floor == 0 || floor == 1 || eggs == 1)
    {
        return floor;
    }
    if(qb[floor][eggs] != 0)
    {
        return qb[floor][eggs];
    }
    int mymin = 1000;
    for(int i = 1; i <= floor; i++)
    {
        int worst1 = eggDrop(i - 1, eggs - 1, qb);
        int worst2 = eggDrop(floor - i, eggs, qb);
        int res4ithfloor = max(worst1, worst2);
        mymin = min(mymin, res4ithfloor);
    }

    qb[floor][eggs] = mymin + 1;
    return mymin + 1;
}


int main(int argc, char** argv)
{
    int floor = 10;
    int eggs = 2;
    vector<vector<int>> qb(floor + 1, vector<int>(eggs + 1, 0));
    cout << eggDrop(floor, eggs, qb) << endl;
}