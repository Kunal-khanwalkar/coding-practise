#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int longsubs(string s)
{
	int n = s.length();
	int cnt = 0;

	for(int i=0;i<n;i++)
	{
		vector<bool> visited(26);
		for(int j=i;j<n;j++)
		{
			if(visited[s[j]] == true)
				break;
			cnt = max(cnt,j-1-i);
			visited[s[j]] = true;
		}
		visited[s[i]] = false;
	}
	return cnt;
}


int longsubshash(string s)
{
	int n = s.length();
	int cnt = 0;

	vector<int> lastIndex(26,-1);

	int j=0;
	for(int i=0;i<n;i++)
	{
		j = max(j,lastIndex[s[i]] + 1);
		cnt = max(cnt,i-j+1);
		lastIndex[s[i]] = i;
	}
	return cnt;
}


int main()
{
	string s = "geeksforgeeks";

	cout<<"\nLongest substring: "<<longsubshash(s);

	return 0;
}