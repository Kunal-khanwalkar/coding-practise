#include<iostream>
#include<algorithm>
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


bool allContainsPrefix(string arr[], int n, string str, int start, int end)
{
	for(int i=0;i<n;i++)
		for(int j=start;j<=end;j++)
			if(arr[i][j] != str[j])
				return false;
	return true;
}

string word2word(string arr[], int n)
{
	int index = INT_MAX;
	for(int i=0;i<n;i++)
		index = min(index,(int)arr[i].length());
	string prefix;

	int low=0, high=index;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if(allContainsPrefix(arr,n,arr[0],low,mid))
		{
			prefix += arr[0].substr(low,mid-low+1);
			low = mid+1;
		}
		else
			high = mid-1;
	}

	return prefix;
}




int main()
{
	string arr[] = {"geeksforgeeks","geeks","geek","geezer"};
	int n = sizeof(arr)/sizeof(arr[0]);

	string ans = word2word(arr,n);

	if(ans.length())
		cout<<"\nLongest common prefix: "<<ans;
	else
		cout<<"\nSad poopoo";
	return 0;
}