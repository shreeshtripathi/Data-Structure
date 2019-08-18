#include<iostream>
using namespace std;
void pd(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    pd(n - 1);
}
int main(){
    pd(5);
}