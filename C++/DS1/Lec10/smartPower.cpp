#include <iostream>
using namespace std;

int power(int num, int pow){
    if(pow == 0){
        return 1;
    }
    int half = power(num, pow / 2);
    if(pow % 2 == 0){
        return half * half;
    } else {
    return half * half * num;
    }
}
int main(){
    int num1 = power(2, 10);
    int num2 = power(2, 11);
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}