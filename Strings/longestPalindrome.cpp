#include<iostream>
using namespace std;


void bruteforce(string str)
{
	int n = str.length();
	int maxlen = 1, start = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			bool flag = true;
			for(int k=0;k<(j-i+1);k++)
				if(str[i+k] != str[j-k])
					flag = false;

			if(flag && (j-i+1) > maxlen)
			{
				start = i;
				maxlen = j-i+1;
			}
		}
	}


	cout<<"\nLongest palindrome: ";
	for(int i=start;i<=start + maxlen-1;i++)
		cout<<str[i];
}


void newbruteforce(string str)
{
	int n = str.length();

	int window = n;
	while(window > 1)
	{
		for(int start=0; start+window<=n; start++)
		{
			bool palinflag = true;
			for(int i=start, j=start+window-1; i<=j; i++, j--)
			{
				if(str[i] != str[j])
				{
					palinflag = false;
					break;
				}
			}
			if(palinflag)
			{
				cout<<"\nFound palindrome: ";
				for(int i=start;i<start+window;i++)
					cout<<str[i];
				return;
			}
		}
		window--;
	}

	cout<<"\nLongest palindrome is of size 1";
}


int expandFromMiddle(string s, int l, int r)
{
	if(s.length() < 1 || l > r)
		return 0;

	while(l>=0 && r<s.length() && s[l] == s[r])
	{
		l--;
		r++;
	}

	return r-l-1;
}


void betterBruteForce(string str)
{
	if(str.length() < 1)
	{
		cout<<"Invalid string";
		return;
	}

	int start=0;
	int end=0;

	for(int i=0;i<str.length();i++)
	{
		int len1 = expandFromMiddle(str,i,i);
		int len2 = expandFromMiddle(str,i,i+1);

		int maxlen = max(len1,len2);

		if(maxlen > end-start)
		{
			start = i - ((maxlen-1)/2);
			end = i + (maxlen/2);
		}
	}

	cout<<"\nLongest palindrome: ";
	for(int i=start;i<=end;i++)
		cout<<str[i];
}



void dp(string str)
{
	int n = str.length();
	bool table[n][n] = {0};
	int maxlen = 1;

	for(int i=0;i<n;i++)
		table[i][i] = true;

	int start = 0;
	for(int i=0;i<n-1;i++)	
		if(str[i] == str[i+1])
		{
			table[i][i+1] = true;
			start = i;
			maxlen = 2;
		}	

	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j = i+k-1;
			if(table[i+1][j-1] && str[i]==str[j])
			{
				table[i][j] = true;
				if(k>maxlen)
				{
					start = i;
					maxlen = k;
				}
			}
		}
	}

	cout<<"\nLongest palindrome: ";
	for(int i=start;i<start+maxlen;i++)
		cout<<str[i];
}


int main()
{
	string str = "forgeeksskeegfor";

	betterBruteForce(str);

	return 0;
}