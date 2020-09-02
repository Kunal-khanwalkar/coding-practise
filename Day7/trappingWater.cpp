#include<iostream>
using namespace std;


int rainWater(int *arr, int n)
{
	int res = 0;

	for(int i=1;i<n-1;i++)
	{
		int l = arr[i];
		for(int j=0;j<i;j++)
			l = max(l,arr[j]);

		int r = arr[i];
		for(int j=i+1;j<n;j++)
			r = max(r,arr[j]);

		res += min(l,r) - arr[i];
	}

	return res;
}


int findMaxWater(int *arr, int n)
{
	int left[n];
	int right[n];
	int res = 0;
	left[0] = arr[0];

	for(int i=1;i<n;i++)	
		left[i] = max(left[i-1],arr[i]);	

	right[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--)
		right[i] = max(right[i+1],arr[i]);

	for(int i=0;i<n;i++)
		res += min(left[i],right[i]) - arr[i];

	return res;
}


int maxWater(int *arr, int n)
{
	int size = n-1;
	int prev = arr[0];
	int prev_index = 0;
	int water = 0;
	int temp = 0;

	for(int i=1;i<n;i++)
	{
		if(arr[i] >= prev)
		{
			prev = arr[i];
			prev_index = i;
			temp = 0;
		}
		else
		{
			water += prev - arr[i];
			temp += prev - arr[i];
		}
	}

	if(prev_index < size)
	{
		water -= temp;
		prev = arr[size];
		for(int i=size;i>=prev_index;i--)
			if(arr[i] >= prev)
				prev = arr[i];
			else
				water += prev - arr[i];
	}

	return water;
}


int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(int);

	cout<<"\nMax water: "<<maxWater(arr,n);

	return 0;	
}