//take a number from user and prin the the nth fibonacci
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the number :";
    cin >> n;
    int a = 0;
    int b = 1;
    while(n != 0){
        int c = a + b;
        a = b;
        b = c;
        n--;
    }
    cout << "nth fibonacci is " << a <<endl;
    return 0;
}