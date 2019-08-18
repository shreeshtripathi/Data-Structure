//Code- diamond
#include<iostream>
using namespace std;
int main(){
    int row;
    cout << "Enter the number of rows :";
    cin >> row;
    int space = row / 2 + 1;
    int star = 1;
    for(int i = 0; i < row; i++){
        for(int i = 0; i < space; i++){
            cout << "  ";
        }
        for(int i = 0; i < star; i++){
            cout << "* ";
        }
        if(i < row / 2){
            space--;
            star += 2 ;
        } else {
            space++;
            star -= 2;
        }
        cout << endl;
    }
    return 0;
}