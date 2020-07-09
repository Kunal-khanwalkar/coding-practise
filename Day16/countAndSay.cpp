#include<iostream>
using namespace std;


void countAndSay(int n)
{
	if(n==1)
	{
		cout<<"1";
		return;
	}
	if(n==2)
	{
		cout<<"1 11";
		return;
	}

	cout<<"1 11 ";
	string str = "11";
	for(int i=3;i<=n;i++)
	{
		str += "$";
		int len = str.length();

		int cnt = 1;
		string tmp = "";

		for(int j=1;j<len;j++)
		{
			if(str[j] != str[j-1])
			{
				tmp += cnt + '0';
				tmp += str[j-1];
				cnt = 1;
			}
			else
				cnt++;
		}

		str = tmp;
		cout<<str<<" ";
	}

}



int main()
{
	int n = 8;
	countAndSay(n);

	return 0;
}