#include<iostream>
using namespace std;


string commonPrefixUtil(string str1, string str2)
{
	string res;
	int n1 = str1.length(), n2 = str2.length();

	for(int i=0,j=0; i<=n1,j<=n2; i++,j++)
	{
		if(str1[i]!=str2[j])
			break;
		res.push_back(str1[i]);
	}
	return res;
}


string commonPrefix(string arr[], int n)
{
	string prefix = arr[0];

	for(int i=1;i<n;i++)
		prefix = commonPrefixUtil(prefix,arr[i]);
	return prefix;
}




int main()
{
	string arr[] = {"geeksforgeeks","geeks","geek","geezer"};
	int n = sizeof(arr)/sizeof(arr[0]);

	string ans = commonPrefix(arr,n);

	if(ans.length())
		cout<<"\nLongest common prefix: "<<ans;
	else
		cout<<"\nSad poopoo";
	return 0;
}