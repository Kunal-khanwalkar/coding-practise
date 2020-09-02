#include<iostream>
using namespace std;



void computeLpsArray(string pat, int m, int lps[])
{
	int len = 0;
	lps[0] = 0;
	int i = 1;

	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}



void kmp(string str, string pat)
{
	int m = pat.length();
	int n = str.length();

	int lps[m];

	computeLpsArray(pat,m,lps);

	int i=0, j=0;

	while(i<n)
	{
		if(pat[j] == str[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"\nFound pattern at: "<<i-j;
			j = lps[j-1];
		}
		else if(i<n && pat[j]!=str[i])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
}



int main()
{
	string text = "GEEKS FOR GEEKS";
	string pat = "GEEK";

	kmp(text,pat);

	return 0;
}