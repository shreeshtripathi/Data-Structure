#include<iostream>
#include<cstring>
using namespace std;

void pmp2(int cr, int cc, int dr, int dc, string asf){

    if(cr == dr && cc == dc){
        cout<< asf << endl;
        return;
    }
    for(int i = 1; i <= dc - cc; i++){
        pmp2(cr, cc + i, dr, dc, asf + "h" + to_string(i));
    }
    for(int i = 1; i <= dr - cr; i++){
        pmp2(cr + i, cc, dr, dc, asf + "v" + to_string(i));
    }
    for(int i = 1; i <= dc - cc && i <= dr - cr; i++){
        pmp2(cr + i, cc + i, dr, dc, asf + "d" + to_string(i));
    }


}



int main(){
    pmp2(0, 0, 2, 2, "");
    return 0;
}