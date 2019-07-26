#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &qb)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	if (qb[n] != 0)
	{
		return qb[n];
	}
	int nm1 = fib(n - 1, qb);
	int nm2 = fib(n - 2, qb);
	int res = nm1 + nm2;
	qb[n] = res;
	return res;
}

int main(int argc, char **argv)
{
	int n = 10;
	vector<int> qb(n + 1, 0);
	cout << fib(n, qb) << endl;
}
