#include<iostream>
using namespace std;


void merge(int *arr, int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1], R[n2];

	for(i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(i=0;i<n2;i++)
		R[i] = arr[m+1+i];

	i=0,j=0;
	k = l;
	
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;			
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
		arr[k++] = L[i++];

	while(j<n2)
		arr[k++] = R[j++];
}


void _mergesort(int *arr, int l, int r)
{
	if(l<r)
	{
		int m = (l + r) / 2;

		_mergesort(arr,l,m);
		_mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}


void mergesort(int *arr, int n)
{
	int l = 0;
	int r = n-1;
	_mergesort(arr,l,r);
}



int main()
{
	int arr[] = {12,11,13,5,6,7,4,3};
	int n = sizeof(arr)/sizeof(int);

	mergesort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	return 0;
}