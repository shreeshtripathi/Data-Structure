#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int bin;
	cin >> bin;
	int pow = 1;	
	int dec = 0;
	while(bin > 0)
	{
		int rem = bin % 10;
		dec = dec + pow * rem;
		pow *= 2;
		bin /= 10;
	}
	cout << dec << endl;
}
