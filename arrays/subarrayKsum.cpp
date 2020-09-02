#include<iostream>
using namespace std;


void bruteForce(int *arr, int n, int k)
{
	for(int i=0;i<n;i++)
	{
		int sum = arr[i];
		for(int j=i+1;j<n;j++)
		{
			if(sum == k)
			{
				cout<<"\nSum found at indexes: "<<i<<" and "<<j-1<<'\n';
				return;
			}
			if(sum > k)
				break;
			sum += arr[j];
		}
	}

	cout<<"\nNo subarray found\n";
}


void ksum(int *arr, int n, int k)
{
	int sum = arr[0];
	int start = 0;

	for(int i=1;i<=n;i++)
	{
		while(sum > k && start < i-1)
		{
			sum -= arr[start];
			start++;
		}

		if(sum == k)
		{
			cout<<"\nSum found between indexes: "<<start<<" and "<<i-1<<"\n";
			return;
		}

		if(i<n)
			sum += arr[i];
	}

	cout<<"\nNo subarray found\n";
}


int main()
{
	int arr[] = {15,2,4,8,9,10,23};
	int n = sizeof(arr)/sizeof(int);
	int k = 23;

	ksum(arr,n,k);

	return 0;
}