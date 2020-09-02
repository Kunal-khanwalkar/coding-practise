#include<iostream>
#include<unordered_map>
using namespace std;


void foudElements(int *arr, int n, int x)
{
	unordered_map<int, pair<int,int>> mp;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			mp[arr[i] + arr[j]] = {i,j};

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			int sum = arr[i] + arr[j];

			if(mp.find(x - sum) != mp.end())
			{
				pair<int,int> p = mp[x-sum];
				if(p.first!=i && p.first!=j && p.second!=i && p.second!=j)
				{
					cout<<arr[i]<<','<<arr[j]<<','<<arr[p.first]<<','<<arr[p.second];
					return;
				}
			}
		}
}


int main()
{
	int arr[] = {10,20,30,40,1,2};
	int n = sizeof(arr)/sizeof(int);
	int x = 91;

	foudElements(arr,n,x);

	return 0;
}