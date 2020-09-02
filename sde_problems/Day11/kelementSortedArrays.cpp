#include<iostream>
using namespace std;



void kthelement(int *arr1, int *arr2, int n1, int n2, int key)
{
	int sorted[n1+n2];
	int i=0,j=0,k=0;

	while(i<n1 && j<n2)
	{
		if(arr1[i] < arr2[j])
			sorted[k++] = arr1[i++];
		else
			sorted[k++] = arr2[j++];
	}

	while(i<n1)
		sorted[k++] = arr1[i++];
	while(j<n2)
		sorted[k++] = arr2[j++];

	cout<<sorted[key-1];
}

int better_kthelement(int *arr1, int *arr2, int n1, int n2, int key)
{
	int i=0,j=0,k=0;

	while(i<n1 && j<n2)
	{		
		k++;
		if(arr1[i] < arr2[j])
		{
			if(k==key)
				return arr1[i];
			i++;
		}
		else
		{
			if(k==key)
				return arr2[j];
			j++;
		}
	}

	while(i < n1)
	{
		k++;
		{
			if(k==key)
				return arr1[i];
			i++;			
		}
	}

	while(j < n2)
	{
		k++;
		{
			if(k==key)
				return arr2[j];
			j++;				
		}
	}

	return -1;
}


int main()
{
	int arr1[] = {2,3,6,7,9};
	int n1 = sizeof(arr1)/sizeof(int);
	int arr2[] = {1,4,8,11};
	int n2 = sizeof(arr2)/sizeof(int);
	int key = 5;

	cout<<better_kthelement(arr1,arr2,n1,n2,key);

	return 0;
}