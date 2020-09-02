#include<iostream>
using namespace std;


int inversionCount(int *arr, int n)
{
	int cnt = 0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i]>arr[j])
				cnt++;

	return cnt;
}





int merge(int *arr, int *temp, int L, int mid, int R)
{
	int i = L;
	int j = mid;
	int k = L;
	int cnt = 0;	

	while((i <= mid-1) && (j <= R))
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			cnt += (mid - i);
		}
	}

	while(i <= mid-1)
		temp[k++] = arr[i++];
	while(j <= R)
		temp[k++] = arr[j++];
	for(i=L;i<=R;i++)
		arr[i] = temp[i];
	return cnt;
}



int _mergesort(int *arr, int *temp, int L, int R)
{
	int mid, cnt = 0;

	if(R>L)
	{
		mid = (L+R)/2;
		cnt += _mergesort(arr,temp,L,mid);
		cnt += _mergesort(arr,temp,mid+1,R);
		cnt += merge(arr,temp,L,mid+1,R);
	}
	return cnt;
}




int mergeSort(int *arr, int n)
{
	int temp[n];
	return _mergesort(arr,temp,0,n-1);
}



int main()
{
	int arr[] = {1,20,6,4,5};
	int n = sizeof(arr)/sizeof(int);

	//cout<<"\nNumber of inversions: "<<inversionCount(arr,n);
	cout<<"\nNumber of inversions: "<<mergeSort(arr,n);

	return 0;
}