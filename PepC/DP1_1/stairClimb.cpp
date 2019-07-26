#include<iostream>
#include<vector>

using namespace std;

int climbStair(int n, vector<int>& qb){
	
	if(n == 0){
		return 1;
	}
	else if(n < 0){
		return 0;
	}
	
	if(qb[n] != 0){
		return qb[n];
	}
	
	int way1 = climbStair(n - 1, qb);
	int way2 = climbStair(n - 2, qb);
	int way3 = climbStair(n - 3, qb);
	
	int ways = way1 + way2 + way3;
	qb[n] = ways;
	
	
	return ways;
}

int main(int argc, char** argv){
	int n = 7;
	vector<int> qb(n + 1, 0);
	cout << climbStair(n, qb) << endl;
}
