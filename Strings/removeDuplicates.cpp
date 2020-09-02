#include<iostream>
#include<set>
using namespace std;


string removeDuplicates(string str)
{
	int n = str.length();
	set<char> S;

	for(int i=0;i<n;i++)
		S.insert(str[i]);	

	string temp;
	
	for(auto x:S)
		temp.push_back(x);

	return temp;
}


string hashing(string str)
{
	int n = str.length();
	set<char> S;

	string temp;

	for(int i=0;i<n;i++)
	{
		if(!S.count(str[i]))
		{
			temp.push_back(str[i]);
			S.insert(str[i]);
		}		
	}

	return temp;
}


int main()
{
	string str = "geeksforgeeks";

	cout<<hashing(str);

	return 0;
}