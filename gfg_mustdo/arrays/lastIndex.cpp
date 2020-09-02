#include<iostream>
using namespace std;


void linearSearch(int *arr, int n)
{
	for(int i=0;i<n;i++)
		if(arr[i] == 1)
		{
			cout<<"\nIndex: "<<i;
			return;
		}
	cout<<"\nNo 1";
}


void binarySearch(int *arr, int n)
{
	int l = 0, r = n-1;

	while(l<=r)
	{
		int mid = (l+r)/2;

		if(arr[mid] == 1 && (mid==0 || arr[mid-1]==0))
		{
			cout<<"\nIndex: "<<mid;
			return;
		}

		if(arr[mid] == 1)
			r = mid-1;
		else
			l = mid+1;
	}
	cout<<"\nNo 1";
}


int main()
{
	int arr[] = {0,0,0,0,0,1,1,1};
	int n = sizeof(arr)/sizeof(int);

	binarySearch(arr,n);

	return 0;
}