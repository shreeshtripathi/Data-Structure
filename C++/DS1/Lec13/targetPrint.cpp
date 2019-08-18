#include<iostream>
#include<cstring>
using namespace std;

void tarPrint(int arr[], int tar, int sp, int n, string asf){

    tarPrint(arr, tar, sp + 1, n, asf);
    tarPrint(arr, tar - arr[sp], sp + 1, n, asf);

}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    // int arr[] = {1, 2, 5, 10, 20, 50}; 
    tarPrint(arr, 70, 0, 7, "");

    return 0;
}