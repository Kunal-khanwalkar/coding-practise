#include<iostream>
#include<unordered_map>
using namespace std;


int countxor(int *arr, int n, int x)
{
	int cnt = 0;

	for(int i=0;i<n;i++)
	{
		int xorsum = 0;
		for(int j=i;j<n;j++)
		{
			xorsum ^= arr[j];
			if(xorsum==x)
				cnt++;
		}
	}

	return cnt;
}



int efficientxor(int *arr, int n, int x)
{
	int cnt=0;
	int *xorArr = new int[n];
	unordered_map<int,int> mp;

	xorArr[0] = arr[0];

	for(int i=1;i<n;i++)
		xorArr[i] = xorArr[i-1]^arr[i];

	for(int i=0;i<n;i++)
	{
		int temp = x^xorArr[i];
		cnt += mp[temp];
		if(xorArr[i] == x)
			cnt++;
		mp[xorArr[i]]++;
	}
	return cnt;
}

int main()
{
	int arr[] = {4,2,2,6,4};
	int n = sizeof(arr)/sizeof(int);
	int x = 6;

	cout<<"\nNumber of subarrays: "<<countxor(arr,n,x);
	return 0;
}