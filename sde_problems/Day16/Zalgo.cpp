#include<iostream>
using namespace std;



void getZarr(string str, int Z[])
{
	int n = str.length();
	int L,R,k;

	L = R = 0;

	for(int i=1;i<n;i++)
	{
		if(i > R)
		{
			L = R = i;
			while(R<n && str[R-L]==str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else
		{
			k = i-L;
			if(Z[k] < R-i+1)
				Z[i] = Z[k];
			else
			{
				L=i;
				while(R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}



void search(string text, string pat)
{
	string concat = pat + "$" + text;
	int l = concat.length();

	int Z[l];
	getZarr(concat,Z);

	for(int i=0;i<l;i++)
	{
		if(Z[i]==pat.length())
			cout<<"\nFound pattern at: "<<i-pat.length()-1<<'\n';
	}
}



int main()
{
	string text = "GEEKS FOR GEEKS";
	string pat = "GEEK";
	search(text,pat);
	return 0;
}