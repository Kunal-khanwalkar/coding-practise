#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;


bool brute(int *arr, int n)
{
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
			{
				if(arr[i]*arr[i] + arr[j]*arr[j] == arr[k]*arr[k] ||
					arr[i]*arr[i] + arr[k]*arr[k] == arr[j]*arr[j] ||
					arr[k]*arr[k] + arr[j]*arr[j] == arr[i]*arr[i])
					return true;
			}
	return false;
}

bool sorting(int *arr, int n)
{
	for(int i=0;i<n;i++)
		arr[i] = arr[i]*arr[i];

	sort(arr,arr+n);

	for(int i=n-1;i>=2;i--)
	{
		int l=0;
		int r=i-1;

		while(l<r)
		{
			if(arr[l] + arr[r] == arr[i])
				return true;
			(arr[l] + arr[r] < arr[i]) ? l++ : r--;
		}
	}

	return false;
}


bool hashing(int *arr, int n)
{
	int max_ele = 0;

	for(int i=0;i<n;i++)
		max_ele = max(max_ele,arr[i]);

	int hash[max_ele+1] = {0};

	for(int i=0;i<n;i++)
		hash[arr[i]]++;

	for(int i=1;i<max_ele+1;i++)
	{
		if(hash[i]==0)
			continue;

		for(int j=1;j<max_ele+1;j++)
		{
			if((i==j && hash[i]==1) || hash[j]==0)
				continue;

			int val = sqrt(i*i + j*j);

			if((val*val) != (i*i + j*j))
				continue;

			if(val > max_ele)
				continue;

			if(hash[val])
				return true;
		}
	}

	return false;
}


int main()
{
	int arr[] = {3,1,4,6,5};
	int n = sizeof(arr)/sizeof(int);

	sorting(arr,n) ? cout<<"\nTrue" : cout<<"\nFalse" ;

	return 0;
}