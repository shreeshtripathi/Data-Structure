//take a number from user, print the reverse of it....
#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number :";
    cin >> num;
    int ans = 0;
    while (num != 0){
        ans = (ans * 10) + (num % 10);
        num = num /10; 
    }
    cout << ans << endl;
    return 0;
}