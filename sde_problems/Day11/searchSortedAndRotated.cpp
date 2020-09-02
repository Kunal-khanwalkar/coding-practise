#include<iostream>
using namespace std;


int binarySearch(int *arr, int l, int r, int key)
{
	
	int mid;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(arr[mid] == key)
			break;

		if(arr[mid] < key)
			l = mid+1;

		else if(arr[mid] > key)
			r = mid-1;
	}

	return mid;
}


int findPivot(int *arr, int l, int r)
{
	if(arr[l]<arr[r])
		return -1;

	int mid;
	while(l<=r)
	{
		mid = (l+r)/2;

		if(arr[mid] > arr[mid+1])
			break;

		if(arr[l] >= arr[mid])
			r = mid-1;
		else
			l = mid+1;

	}

	return mid;
}



int pivotedSearch(int *arr, int n, int key)
{
	int pivot = findPivot(arr,0,n-1);	
	cout<<"\nPivot: "<<pivot<<'\n';

	if(pivot==-1)
		return binarySearch(arr,0,n-1,key);

	if(arr[pivot]==key)
		return pivot;

	if(arr[0] <= key)
		return binarySearch(arr,0,pivot-1,key);
	
	return binarySearch(arr,pivot+1,n-1,key);

}


int main()
{
	int arr[] = {4,5,6,7,1,2,3};
	int n = sizeof(arr)/sizeof(int);
	int key = 5;

	cout<<"\nIndex of element: "<<pivotedSearch(arr,n,key);

	return 0;
}