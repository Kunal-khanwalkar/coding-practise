#include<iostream>
#include<algorithm>
using namespace std;


void rearrange(int *arr, int n)
{
	int temp[n];
	int small = 0, large = n-1;
	bool flag = false;

	for(int i=0;i<n;i++)
	{
		flag = !flag;

		if(flag)
			temp[i] = arr[large--];
		else
			temp[i] = arr[small++];
	}

	for(int i=0;i<n;i++)
		arr[i] = temp[i];
}


void optimized(int *arr, int n)
{
	int max_idx = n-1, min_idx = 0;
	int max_ele = arr[n-1] + 1;

	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			arr[i] += (arr[max_idx] % max_ele) * max_ele;
			max_idx--;
		}
		else
		{
			arr[i] += (arr[min_idx] % max_ele) * max_ele;
			min_idx++;
		}
	}

	for(int i=0;i<n;i++)
		arr[i] = arr[i] / max_ele;
}



int main()
{
	int arr[] = {1,5,9,10,12,15};
	int n = sizeof(arr)/sizeof(int);

	optimized(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	return 0;
}