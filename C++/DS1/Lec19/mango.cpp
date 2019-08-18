#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool isValid(vector<string> vocab, string str){
    for(int i = 0; i < vocab.size(); i++){
        if(str.compare(vocab[i]) == 0){
            //vocab[i] == str
            return true;
        }
    }

    return false;
}

void wordBreak(vector<string> vocab, string q, string ans){

    if(q.length() == 0){
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < q.length(); i++){
        string sstr = q.substr(0, i + 1);
        string ros = q.substr(i + 1, q.length());
        if(isValid(vocab, sstr)){
            string ros = q.substr(i + 1, q.length());
            wordBreak(vocab, ros, ans + sstr + '-');
        }
    }

}


int main(){

    vector<string> vocab {
        "man", "mango", "go", "ice", "cream", "air", "plane", "icecream", "airplane", "manic"
    };

    wordBreak(vocab, "mangoicecreamairplane", "");

    return 0;
}