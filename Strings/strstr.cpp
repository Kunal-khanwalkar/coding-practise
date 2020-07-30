#include<iostream>
using namespace std;


int strstr(string s1, string s2)
{
	int n = s1.length();
	int k = s2.length();

	for(int i=0; i<n-k;i++)
	{
		int j=0;
		while(j<k)
		{
			if(s1[i+j] != s2[j])
				break;
			j++;
		}

		if(j==k)
			return i;
	}

	return -1;
}



int main()
{
	string s1 = "geeksforgeeks";
	string s2 = "for";

	cout<<"\nIndex of substring: "<<strstr(s1,s2);

	return 0;
}