//Right angled triangle
#include <iostream>
using namespace std;
int main(){
    int row;
    cout << "Enter the number of rows : ";
    cin >> row;
    for(int i = 0; i < row; i++){
        for(int j = 0; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}