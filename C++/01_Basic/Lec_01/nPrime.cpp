//print prime number from 1 to n
#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number : ";
    cin >> num;
    int count = 2;
    while (count <= num){
        bool prime = true;
        int i = 2;
        while(i * i <= count){
            if(count % i == 0){
                prime = false;
                break;
            }
            i++;
        }
        if(prime){
            cout << count << " ";
        }
        count++;
    }
    cout << endl;
    return 0;
}