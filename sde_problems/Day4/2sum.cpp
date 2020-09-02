#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;


bool sum2(int *arr, int n, int x)
{
	int l,r;
	sort(arr,arr+n);

	l = 0;
	r = n-1;
	while(l<r)
	{
		if(arr[l] + arr[r] == x)
			return true;
		else if(arr[l] + arr[r] < x)
			l++;
		else
			r--;
	}
	return false;
}


void printPair(int *arr, int n, int x)
{
	unordered_set<int> s;

	for(int i=0;i<n;i++)
	{
		int temp = x - arr[i];

		if(s.find(temp) != s.end())
			cout<<"\nPair: "<<arr[i]<<","<<temp;
		s.insert(arr[i]);
	}
}


int main()
{
	int arr[] = {1, 4, 45, 6, 10, -8};
	int n = sizeof(arr)/sizeof(int);
	int x = 16;

	printPair(arr,n,x);

	if(sum2(arr,n,x))
		cout<<"\nYes pair";
	else
		cout<<"\nNo pair";
	return 0;


	
}