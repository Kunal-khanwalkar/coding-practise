#include<iostream>
using namespace std;



int myatoi(string s)
{
	int res=0;
	int start=0;
	int sign = 1;
	if(s[0]=='-')
	{
		sign = -1;
		start=1;
	}

	for(int i=start;i<s.length();i++)
	{
		res = res*10 + s[i]-'0';
	}
	return sign*res;
}



int main()
{
	char str[] = "-89789";
	cout<<myatoi(str);
	return 0;
}