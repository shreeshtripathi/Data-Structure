#include <iostream>
using namespace std;
void pdi(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    pdi(n - 1);
    cout << n << " ";
}
int main(){
    pdi(5);
    cout << endl;
    return 0;
}