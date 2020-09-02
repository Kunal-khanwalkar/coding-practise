#include<iostream>
using namespace std;


void bruteforce(int *arr, int n)
{	

	for(int i=0;i<n;i++)
	{
		bool flag = false;

		for(int j=0;j<=i;j++)
		{
			if(arr[j] > arr[i])
			{
				flag = true;
				break;
			}
		}

		for(int j=i+1;j<n;j++)
		{
			if(arr[j] < arr[i])
			{
				flag = true;
				break;
			}
		}

		if(flag == false)
		{
			cout<<"\nElement found: "<<arr[i];
			return;
		}
	}

	cout<<"\nNo such element found";
}



void efficient(int *arr, int n)
{
	int leftMax[n];
	leftMax[0] = INT_MIN;
	for(int i=1;i<n;i++)
		leftMax[i] = max(leftMax[i-1],arr[i-1]);

	int rightMin = INT_MAX;

	for(int i=n-1;i>=0;i--)	
	{
		if(leftMax[i] < arr[i] && rightMin > arr[i])
		{
			cout<<"\nElement found: "<<arr[i];
			return;
		}
		rightMin = min(rightMin,arr[i]);
	}

	cout<<"\nNo such element found";
}


int main()
{
	int arr[] = {5,1,4,3,6,8,10,7,9};
	int n = sizeof(arr)/sizeof(int);

	efficient(arr,n);

	return 0;
}