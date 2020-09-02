#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;


void bruteforce(int *arr, int n, int ksum)
{
	bool found = false;

	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
			{
				if(arr[i]+arr[j]+arr[k] == ksum)
				{
					cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<endl;
					found = true;					
				}
			}
	if(found == false)
		cout<<"\nNo triplet with "<<ksum<<" sum";
}


void hashing(int *arr, int n, int ksum)
{
	bool found = false;
	for(int i=0;i<n-1;i++)
	{
		unordered_set<int> S;
		for(int j=i+1;j<n;j++)
		{
			int x = arr[i] + arr[j];
			if(S.find(ksum-x) != S.end())
			{
				cout<<x<<' '<<arr[i]<<' '<<arr[j]<<endl;
				found = true;
			}
			else
				S.insert(arr[j]);
		}
	}
	if(found == false)
		cout<<"\nNo triplet with "<<ksum<<" sum";
}


void sorting(int *arr, int n, int ksum)
{
	sort(arr,arr+n);
	bool found = false;

	for(int i=0;i<n-1;i++)
	{
		int l = i+1;
		int r = n-1;
		int x = arr[i];
		while(l<r)
		{
			if(x+arr[l]+arr[r] == ksum)
			{
				cout<<x<<' '<<arr[l]<<' '<<arr[r]<<endl;
				l++;
				r--;
				found = true;
			}
			else if(x+arr[l]+arr[r] < ksum)
				l++;
			else
				r--;
		}
	}
	if(found == false)
		cout<<"\nNo triplet with "<<ksum<<" sum";
}



int main()
{
	int arr[] = {12,3,4,1,6,9};
	int n = sizeof(arr)/sizeof(int);
	int ksum = 24;

	//bruteforce(arr,n,ksum);
	hashing(arr,n,ksum);
	//sorting(arr,n,ksum);

	return 0;
}
