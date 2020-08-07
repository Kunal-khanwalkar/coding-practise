#include<iostream>
using namespace std;


int partition_last(int *arr, int l, int r)
{
	int pivot = arr[r];
	int i = l-1;

	for(int j=l;j<r;j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}



void _quicksort(int *arr, int l, int r)
{
	if(l<r)
	{
		int pi = partition_last(arr,l,r);
		_quicksort(arr,l,pi-1);
		_quicksort(arr,pi+1,r);
	}
}


void quicksort(int *arr, int n)
{
	int l = 0;
	int r = n-1;
	_quicksort(arr,l,r);
}



int main()
{
	int arr[] = {12,11,13,5,6,7,4,3};
	int n = sizeof(arr)/sizeof(int);

	quicksort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	return 0;
}