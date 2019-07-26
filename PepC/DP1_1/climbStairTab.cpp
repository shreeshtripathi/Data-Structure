#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int climbStairTab(vector<int> &jumpArr)
{
	vector<int> strg(jumpArr.size());
	strg[0] = 1;
	for (int s = 1; s < jumpArr.size(); s++)
	{
		for (int js = 1; js <= jumpArr[s]; js++)
		{
			int i = s - js;
			if (i >= 0)
			{
				strg[s] += strg[i];
			}
		}
	}

	return strg[strg.size() - 1];
}

void allMinPath(int n, vector<int> &strg, string psf)
{
	if (n == 0)
	{
		cout << psf << endl;
		return;
	}

	
}

int minJumps(vector<int> &jumpArr)
{

	vector<int> strg(jumpArr.size(), 0);
	strg[0] = 0;

	for (int s = 1; s < jumpArr.size(); s++)
	{

		if (jumpArr[s] == 0)
		{
			strg[s] = -1;
			continue;
		}
		int mymin = INT_MAX;
		for (int js = 1; js <= jumpArr[s]; js++)
		{

			int i = s - js;
			if (i >= 0 && strg[i] != -1)
			{
				mymin = min(strg[i], mymin);
			}
		}
		if (mymin != INT_MAX)
		{
			strg[s] = mymin + 1;
			// cout << strg[s] << endl;
		}
		else
		{
			strg[s] = -1;
		}
	}

	for (int i = 0; i < strg.size(); i++)
	{
		cout << strg[i] << " ";
	}
	cout << endl;
	return strg[strg.size() - 1];
}

int main(int argc, char **argv)
{
	int n = 8;
	vector<int> jumpArr{0, 2, 3, 1, 0, 2, 0, 2, 4};
	// cout << climbStairTab(jumpArr) << endl;

	cout << minJumps(jumpArr) << endl;
}
