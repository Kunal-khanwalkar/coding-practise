#include<iostream>
#include<unordered_set>
using namespace std;



int lcs(int *arr, int n)
{
	unordered_set<int> S;
	int res = 0;

	for(int i=0;i<n;i++)
		S.insert(arr[i]);

	for(int i=0;i<n;i++)
	{
		if(S.find(arr[i] - 1) == S.end())
		{
			int j = arr[i];
			while(S.find(j) != S.end())
				j++;
			res = max(res, j - arr[i]);
		}
	}
	return res;
}


int main()
{
	int arr[] = {1,9,3,10,4,20,2};
	int n = sizeof(arr)/sizeof(int);

	cout<<"\nLongest consecutive subsequence: "<<lcs(arr,n);

	return 0;
}