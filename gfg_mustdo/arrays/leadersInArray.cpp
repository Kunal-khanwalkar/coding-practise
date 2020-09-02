#include<iostream>
using namespace std;


void naive(int *arr, int n)
{
	for(int i=0;i<n;i++)
	{
		int j;
		for(j=i+1;j<n;j++)
		{
			if(arr[i] < arr[j])
				break;
		}
		if(j == n)
			cout<<arr[i]<<' ';
	}
}


void leaders(int *arr, int n)
{
	int cmax = arr[n-1];
	cout<<cmax<<' ';

	for(int i=n-2;i>=0;i--)
	{
		if(arr[i] > cmax)
		{
			cmax = arr[i];
			cout<<cmax<<' ';
		}
	}
}


int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]); 

    leaders(arr,n);

	return 0;
}