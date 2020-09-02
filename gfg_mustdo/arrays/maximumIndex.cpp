#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;


void bruteForce(int *arr, int n)
{
	int maxDiff = -1;
	int i,j;

	for(i=0;i<n;i++)
		for(j=n-1;j>i;j--)
			if(arr[j] > arr[i] && maxDiff < (j-i))
				maxDiff = j-i;

	cout<<"\nMaximum difference: "<<maxDiff;
}


void sorting(int *arr, int n)
{

	unordered_map<int,int> mp;

	for(int i=0;i<n;i++)	
		mp[arr[i]] = i;	

	sort(arr,arr+n);
	int maxDiff = 0, temp = n;

	for(int i=0;i<n;i++)
	{
		if(temp > i)
			temp = i;
		maxDiff = max(maxDiff, i - temp - 1);
	}

	cout<<"\nMaximum difference: "<<maxDiff;	
}



int main()
{
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    sorting(arr,n);

	return 0;
}