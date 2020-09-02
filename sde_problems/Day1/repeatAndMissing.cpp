#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int *arr, int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<' ';
}

void sorting(int *arr, int size)
{
	sort(arr,arr + size);
	for(int i=0;i<size;i++)	
		if(arr[i] != i+1)
		{
			cout<<"\nMissing element: "<<i+1;
			cout<<"\nRepeated element: "<<arr[i];
			break;
		}	
}

void countArray(int *arr, int size)
{
	int temp[size] = {0};
	int i;
	for (i=0;i<size;i++)
	{
		if(temp[arr[i]] == 0)
			temp[arr[i]] = 1;
		else if(temp[arr[i]] == 1)
			cout<<"\nRepeating element: "<<arr[i]<<' ';
	}

	for(i=0;i<size;i++)
		if(temp[i]==0)
		{
			cout<<"\nMissing element: "<<i+1<<' ';
			break;
		}
}

void absmethod(int *arr, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout<<"\nRepeating element: "<<abs(arr[i])<<' ';
	}

	for(i=0;i<size;i++)
	{
		if(arr[i]>0)
			cout<<"\nMissing element: "<<i+1;
	}
}

int main()
{
	int arr[] = {4,3,6,2,1,1};	
	int size = sizeof(arr)/sizeof(int);

	sorting(arr,size);
	//countArray(arr,size);
	//absmethod(arr,size);

	return 0;
}