#include<iostream>
using namespace std;


int myatoi(string s)
{
	int res=0,start=0,sign=1;

	if(s[0] == '-')
	{
		sign = -1;
		start = 1;
	}

	for(int i=start;i<s.length();i++)
	{
		res = res*10 + s[i]-'0';
	}

	return sign*res;
}


int main()
{
	string s = "-89789";

	cout<<myatoi(s);

	return 0;
}