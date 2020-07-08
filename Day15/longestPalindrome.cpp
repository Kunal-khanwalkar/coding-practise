#include<iostream>
using namespace std;


void bruteForce(string s)
{
	int n = s.size();
	int maxlength = 1, start = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int flag = 1;
			for(int k=0;k<(j-i+1)/2;k++)
				if(s[i+k] != s[j-k])
					flag = 0;
			if(flag==1 && (j-i+1) > maxlength)
			{
				start = i;
				maxlength = j-i+1;
			}
		}
	}

	for(int i=start;i<start + maxlength;i++)
		cout<<s[i];
}



void betterBruteForce(string s)
{
	int n = s.length();

	for(int i=n;i>0;i--)
	{		
		int wSize = i;
		int loops = n - wSize;
		int loop=0;
		cout<<wSize<<' ';
		while(loop <= loops)
		{			
			bool flag = false;			
			for(int j=loop;j<(wSize/2)+loop;j++)
			{
				cout<<s[j];
				if(s[j] != s[loop+wSize - j])
				{
					flag = true;
					break;
				}
			}
			if(flag==false)
			{
				cout<<'\n';
				for(int j=0;j<loop+wSize;j++)
					cout<<s[j];
				return;
			}

			cout<<' ';
			loop++;
		}		
		cout<<endl;
	}
}



void dp(string s)
{
	int n = s.length();
	bool table[n][n] = {false};
	int maxlength = 1;

	for(int i=0;i<n;i++)
		table[i][i] = true;

	int start = 0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i] == s[i+1])
		{
			table[i][i+1] = true;
			start = i;
			maxlength = 2;
		}
	}


	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j = i+k-1;

			if(table[i+1][j-1] && s[i]==s[j])
			{
				table[i][j] = true;
				if(k>maxlength)
				{
					start = i;
					maxlength = k;
				}
			}

		}
	}


	for(int i=start;i<start+maxlength;i++)
		cout<<s[i];		
}


int main()
{
	string s = "forgeeksskeegfor";
	cout<<"\nLongest palindrome: ";
	//bruteForce(s);
	//betterBruteForce(s);
	dp(s);
	return 0;
}