#include<iostream>
using namespace std;


void counting(int *arr, int n)
{
	int n0s = 0, n1s = 0, n2s = 0;
	for(int i=0;i<n;i++)
	{
		switch(arr[i])
		{
			case 0: n0s++;
					break;
			case 1: n1s++;
					break;
			case 2: n2s++;
					break;
		}
	}

	for(int i=0;i<n0s;i++)
		arr[i] = 0;
	for(int i=n0s;i<n0s + n1s;i++)
		arr[i] = 1;
	for(int i=n0s + n1s; i<n0s+n1s+n2s; i++)
		arr[i] = 2;
}



void kadane(int *arr, int n)
{
	int low = 0, mid = 0, high = n-1;

	while(mid <= high)
	{
		switch(arr[mid])
		{
			case 0: swap(arr[low++],arr[mid++]);
					break;
			case 1: mid++;
					break;
			case 2: swap(arr[high--],arr[mid]);
					break;
		}
	}
}


int main()
{
	int arr[] = {0,2,1,1,0,0};
	int n = sizeof(arr)/sizeof(int);

	kadane(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	return 0;
}