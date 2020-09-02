#include<iostream>
using namespace std;


int ColumnNumber(string s)
{
	int result = 0;

	for(auto i=s.begin(); i!=s.end(); i++)
	{		
		result *= 26;
		result += *i - 'A' + 1;
	}
	return result;
}


int main()
{
	cout<<ColumnNumber("CDA")<<'\n';
	return 0;
}