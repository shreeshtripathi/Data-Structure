#include<iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter a number to check it is prime or not : " << endl;
    cin >> num;
    if(num == 1){
        cout << "1 is nether prime nor composite" << endl;
        return 0;
    }
    int i = 2;
    while (i * i <= num){
        if (num % i == 0){
            cout << num << " is composite number" << endl;
            return 0;
        }
        i++;
    }
    cout << num << " is a prime number" << endl;
    return 0;
}