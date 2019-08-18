#include <iostream>
using namespace std;
void pdis(int n){
    if(n == 0){
        return;
    }
    if(n % 2 == 1)
    cout << n << " ";
    pdis(n - 1);
    if(n % 2 == 0)
    cout << n << " ";
}
int main(){
    pdis(7);
    cout << endl;
    return 0;
}