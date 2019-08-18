#include<iostream>
using namespace std;
int main(){
    int a = 10;
    int b = 30;
    int c = 80;
    if(a > b && a > c){
        cout<<"a is largest number i.e. "<<a<<endl;
    }else if(b >= c){
        cout<<"b is largest number i.e. "<<b<<endl;
    } else{
        cout<<"c is largest number i.e. "<<c<<endl;
    }
    return 0;
}