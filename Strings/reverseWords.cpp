#include<iostream>
#include<algorithm>
using namespace std;


void reverseWords(string &s)
{
	int start = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		{
			reverse(s.begin() + start, s.begin() + i);
			start = i+1;
		}
	}

	reverse(s.begin() + start, s.end());

	reverse(s.begin(), s.end());
}


int main()
{
	string s = "I want to kill myself";

	reverseWords(s);

	cout<<s;

	return 0;
}