#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> lpsCalcuator(string& pat)
{
	vector<int> lps(pat.length(), 0);
	int l = 0;
	int i = 1;
	while(i < pat.length())
	{
		if(pat[i] == pat[l])
		{
			lps[i] = l + 1;
			i++;
			l++;

		}
		else
		{
			if(l > 0)
			{
				l = lps[l - 1];
			}
			else
			{
				i++;
			}
			
		}
		
	}
	return lps;
}

void kmp(string& src, string& pat)
{
	vector<int> lps = lpsCalcuator(pat);
	int i = 0;
	int j = 0;
	while(i < src.length())
	{
		if(i == j)
		{
			i++;
			j++;
			if(j == pat.length())
			{
				cout << i - j << " ";
				j = lps[j - 1];	
			}
		}
		else
		{
			if(j > 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
				j = 0;
			}
			
		}
	}
	cout << endl;
}


int main(int argc, char** argv)
{
	string src = "";
	string pat = "";
	kmp(src, pat);
}
