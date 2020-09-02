#include<iostream>
using namespace std;


int maxsum(int *arr, int n, int k)
{

	while(k>0)
	{

		int min = INT_MAX;
		int index;
		for(int i=0;i<n;i++)
		{
			if(arr[i] < min)
			{
				min = arr[i];
				index = i;
			}
		}

		if(min>=0)
			break;

		arr[index] = -arr[index];

		k--;
	}

	int sum=0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	return sum;
}



int main()
{
	int arr[] = {-2,0,5,-1,2};
	int k=4;
	int n = sizeof(arr)/sizeof(int);

	cout<<"Maxsum: "<<maxsum(arr,n,k);

	return 0;
}