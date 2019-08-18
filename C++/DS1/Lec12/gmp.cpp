#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<string> gmp2(int cr, int cc, int dr, int dc){
    if(cc == dc && cr == dr){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> mres;
    for(int i = 1; i <= dc - cc; i++){
        vector<string> rr = gmp2(cr, cc + i, dr, dc);
        for(int j = 0; j < rr.size(); j++){
            mres.push_back("h" + to_string(i) + rr[j]);
        }
    }
    for(int i = 1; i <= dr - cr; i++){
        vector<string> rr = gmp2(cr + i, cc, dr, dc);
        for(int j = 0; j < rr.size(); j++){
            mres.push_back("v" + to_string(i) + rr[j]);
        }
    }
    for(int i = 1; i <= dc - cc && i <= dr - cr; i++){
        vector<string> rr = gmp2(cr + i, cc + i, dr, dc);
        for(int j = 0; j < rr.size(); j++){
            mres.push_back("d" + to_string(i) + rr[j]);
        }
    }
    return mres;
}

vector<string> gmp1(int cr, int cc, int dr, int dc){

    if(cr == dr && cc == dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    if(cr > dr || cc > dc){
        vector<string> bres;
        return bres;
    }
    vector<string> hres = gmp1(cr, cc + 1, dr, dc);
    vector<string> vres = gmp1(cr + 1, cc, dr, dc);
    vector<string> mres;
    for(int i = 0; i < hres.size(); i++){
        mres.push_back("H " + hres[i]);
    }
    for(int i = 0; i < vres.size(); i++){
        mres.push_back("V " + vres[i]);
    }
    return mres;

}

int main(){
    vector<string> vs1 = gmp1(0, 0, 2, 2);
    vector<string> vs2 = gmp2(0, 0, 2, 2);
    for(int i=0;i<vs2.size();i++)
	{
		cout<<vs2[i]<<endl;
	}
    for(int i = 0; i < vs1.size(); i++){
        cout << vs1[i] << endl;
    }
    return 0;
}