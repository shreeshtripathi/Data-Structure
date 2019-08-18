//Code- Hollow diamond
#include<iostream>
using namespace std;
int main(){
    int row;
    cout << "Enter the number of rows :";
    cin >> row;
    int space = 1;
    int star = row / 2 + 1;
    for(int i = 0; i < row; i++){
        for(int i = 0; i < star; i++){
            cout << "* ";
        }
        for(int i = 0; i < space; i++){
            cout << "- ";
        }
        for(int i = 0; i < star; i++){
            cout << "* ";
        }
        if(i < row / 2){
            space += 2;
            star -- ;
        } else {
            space -= 2;
            star ++;
        }
        cout << endl;
    }
    return 0;
}