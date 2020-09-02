#include<iostream>
using namespace std;


int selsort(int *arr, int n)
{
	int cnt=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i] > arr[j])
				cnt++;
	return cnt;
}




int merge(int *arr, int *temp, int left, int mid, int right)
{
	int cnt=0;
	int i = left, j = mid, k = left;

	while((i <= mid-1) && (j <= right))
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			cnt += (mid-i);
		}
	}

	while(i<=mid-1)
		temp[k++] = arr[i++];
	while(j<=right)
		temp[k++] = arr[j++];
	for(i=left;i<=right;i++)
		arr[i] = temp[i];

	return cnt;
}


int _mergesort(int *arr, int *temp, int left, int right)
{
	int mid, cnt = 0;
	if(right > left)
	{
		mid = (left + right)/2;
		cnt += _mergesort(arr,temp,left,mid);
		cnt += _mergesort(arr,temp,mid+1,right);
		cnt += merge(arr,temp,left,mid+1,right);
	}
	return cnt;
}

int mergesort(int *arr, int n)
{
	int temp[n];
	return _mergesort(arr,temp,0,n-1);
}

int main()
{
	int arr[] = {1,20,6,4,5};
	int n = sizeof(arr)/sizeof(int);

	cout<<"\nNumber of inversions: "<<mergesort(arr,n);

	return 0;
}