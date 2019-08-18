#include<iostream>
#include<vector>
using namespace std;

void assign(){
    vector<int> v1 = {10, 20, 30};
    vector<int> v2 = v1;
    v1.push_back(40);
    v2.push_back(50);
    v2.push_back(80);

    cout << v1.size() << " "  << v2.size() << endl;
}

int main(){
    assign();
}