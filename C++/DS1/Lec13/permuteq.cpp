#include<iostream>
#include<cstring>
using namespace std;

void permute(int bm, int cq, int tq, int tb, string asf){
    if(cq > tq){
        cout << asf << endl;
        return;
    }

     for(int i = 0; i < tb; i++){
         if((bm & (1 << i)) == 0){
             bm = bm ^ (1 << i);
             permute(bm, cq + 1, tq, tb, asf + "q" + to_string(cq) + "b" + to_string(i) + " ");
             bm = bm ^ (1 << i);
         }
     }
}

int main(){
    permute(0, 1, 2, 5, "");
    return 0;
}