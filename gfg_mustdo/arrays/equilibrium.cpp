#include<iostream>
using namespace std;


int equi(int *arr, int n)
{
	int lsum, rsum;
	for(int i=0;i<n;i++)
	{
		lsum = 0;
		for(int j=0;j<i;j++)
			lsum += arr[j];

		rsum = 0;
		for(int j=i+1;j<n;j++)
			rsum += arr[j];

		if(lsum == rsum)
			return i;
	}

	return -1;
}


int efficientequi(int *arr, int n)
{
	int sum=0;
	int lsum=0;

	for(int i=0;i<n;i++)
		sum += arr[i];

	for(int i=0;i<n;i++)
	{
		sum -= arr[i];
		if(lsum == sum)
			return i;
		lsum += arr[i];
	}

	return -1;
}


int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout<<"\nEquilibrium point: "<<efficientequi(arr,n);

	return 0;
}