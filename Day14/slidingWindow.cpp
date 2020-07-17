#include<iostream>
#include<deque>
using namespace std;



void printKMax(int *arr, int n, int k)
{
	int i,j, max;

	for(i=0;i<=n-k;i++)
	{
		max = arr[i];
		for(j=1;j<k;j++)
		{
			if(arr[i + j] > max)
				max = arr[i+j];
		}
		cout<<max<<' ';
	}
}


void dequeMethod(int *arr, int n, int k)
{
	deque<int> q(k);
	int i;

	for(i=0;i<k;i++)
	{
		while(!q.empty() && arr[i] >= arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	while(i<n)
	{
		cout<<arr[q.front()]<<' ';

		while(!q.empty() && q.front() <= i-k)
			q.pop_front();
		while(!q.empty() && arr[i] >= arr[q.back()])
			q.pop_back();

		q.push_back(i);
		i++;
	}
	cout<<arr[q.front()];
}


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(int);
	int k = 3;

	dequeMethod(arr,n,k);

	return 0;
}