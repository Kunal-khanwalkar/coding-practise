#include<iostream>
using namespace std;


void summ(int *arr, int n)
{
	int total = (n+1)*(n+2)/2;

	for(int i=0;i<n;i++)	
		total -= arr[i];

	cout<<"\nMissing number: "<<total;
}

void bettersumm(int *arr, int n)
{
	int total = 1;

	for(int i=2;i<(n+2);i++)
	{
		total += i;
		total -= arr[i-2];
	}

	cout<<"\nMissing number: "<<total;	
}


void xormethod(int *arr, int n)
{
	int x1 = arr[0];
	for(int i=1;i<n;i++)
		x1 ^= arr[i];

	int x2 = 1;
	for(int i=2;i<n+2;i++)
		x2 ^= i;

	int total = x1 ^ x2;
	cout<<"\nMissing number: "<<total;		
}


int main()
{
	int arr[] = {1,2,4,5,6};
	int n = sizeof(arr)/sizeof(int);

	bettersumm(arr,n);

	return 0;
}