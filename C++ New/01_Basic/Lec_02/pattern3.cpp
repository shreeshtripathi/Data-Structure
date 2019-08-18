//Right angled triangle of fibbonacci number
#include <iostream>
using namespace std;
int main(){
    int row;
    cout << "Enter the number of rows : ";
    cin >> row;
    int a = 0;
    int b = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j <= i; j++){
            cout << a << " ";
            int c = a + b;
            a = b;
            b = c;
        }
        cout << endl;
    }
    return 0;
}