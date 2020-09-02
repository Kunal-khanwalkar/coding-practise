#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


void assignUsernames(string s[], int n)
{
	map<string,int> mp;

	for(int i=0;i<n;i++)
	{
		if(!mp.count(s[i]))
			mp[s[i]] = 1;
		else
		{			
			string temp = s[i] + to_string(mp[s[i]]);
			while(mp.count(temp))
				temp = s[i] + to_string(++mp[s[i]]);
			mp[temp] = 1;
			s[i] = temp;
		}	
	}
}

int main()
{
	string s[] = {"a1","a","a","a1","b","b"};
	int n = 6;

	assignUsernames(s,n);

	cout<<"\nUsernames are: ";
	for(auto x:s)
		cout<<x<<' ';

	return 0;
}