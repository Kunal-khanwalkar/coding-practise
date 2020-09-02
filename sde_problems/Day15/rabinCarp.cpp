#include<iostream>
using namespace std;



void rabinSearch(string s, string pat, int q)
{
	int n = s.size();
	int m = pat.size();
	int i,j, p=0, t=0, h=1, d=256;

	//h = pow(d,m-1)%q
	for(i=0;i<m-1;i++)
		h = (h*d)%q;

	//hash of pattern and first window text
	for(i=0;i<m;i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + s[i])%q;
	}

	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
				if(s[i+j] != pat[j])
					break;
			if(j==m)
				cout<<"\nPattern found at: "<<i<<'\n';
		}		

		if(i < n-m)
		{
			t = (d*(t-s[i]*h) + s[i+m])%q;
			if(t<0)
				t += q;
		}
	}

}




int main()
{
	string s = "GEEKS FOR GEEKS";
	string pat = "GEEK";
	int q = 101;

	rabinSearch(s,pat,q);
	
	return 0;
}