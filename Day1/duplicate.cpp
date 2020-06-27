#include<iostream>
using namespace std;


void absmethod(int *arr, int size)
{
	for (int i=0;i<size;i++)
	{
		if (arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout<<abs(arr[i])<<' ';
	}
	cout<<endl;
}


void modulusmethod(int *arr, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		arr[arr[i]%size] += size;	
	}

	for(i=0;i<size;i++)
	{
		if(arr[i] >= size*2)
		{
			cout<<i<<' ';
		}
	}
	cout<<endl;
}


int main()
{
	int arr1[] = {1,2,3,1,3,6,6};
	int size = sizeof(arr1)/sizeof(int);

	absmethod(arr1,size);	
	int arr2[] = {1,2,3,1,3,6,6};
	modulusmethod(arr2,size);
	
	return 0;
}