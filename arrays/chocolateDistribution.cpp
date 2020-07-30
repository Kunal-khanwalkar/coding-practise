#include<iostream>
#include<algorithm>
using namespace std;


void distribution(int *arr, int n, int m)
{
	if(m==0 || n==0)
	{
		cout<<"\nBruh";
		return;
	}

	sort(arr, arr+n);

	if(n<m)
	{
		cout<<"\nStudents more than packets bruh";
		return;
	}

	int min_diff = INT_MAX;
	for(int i=0; i+m-1<n; i++)
	{
		int diff = arr[i+m-1] - arr[i];
		if(diff < min_diff)
			min_diff = diff;
	}

	cout<<"\nMin diff: "<<min_diff;
}




int main()
{
	int arr[] = {7,3,2,4,9,12,56};
	int n = sizeof(arr)/sizeof(int);
	int m = 3;

	distribution(arr,n,m);

	return 0;
}