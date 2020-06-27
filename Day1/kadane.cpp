#include<iostream>
#include<climits>
using namespace std;


int kadane(int *arr, int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
	int s,i,start,end;

	for(i=0;i<size;i++)
	{
		max_ending_here += arr[i];

		if(max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i+1;
		}
		else if(max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}
	}

	cout<<"\nStarting index: "<<start;
	cout<<"\nEnding index: "<<end;
	return max_so_far;
}

int maxSum(int *arr, int size)
{
	int max_so_far = arr[0];
	int curr_max = arr[0];

	for(int i=1;i<size;i++)
	{
		curr_max = max(arr[i], curr_max + arr[i]);
		max_so_far = max(max_so_far, curr_max);
	}

	return max_so_far;
}

int main()
{
	int arr[] = {-2,-3,4,-1,-2,1,5,-3};
	int size = sizeof(arr)/sizeof(int);

	int max_sum = kadane(arr,size);
	cout<<"\nMax contiguous sum: "<<max_sum;
}