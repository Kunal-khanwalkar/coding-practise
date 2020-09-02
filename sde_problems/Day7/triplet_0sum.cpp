#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;


void bruteforce(int *arr, int n)
{
	bool found = false;

	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
			{
				if(arr[i]+arr[j]+arr[k] == 0)
				{
					cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<endl;
					found = true;					
				}
			}
	if(found == false)
		cout<<"\nNo triplet with 0 sum";
}


void hashing(int *arr, int n)
{
	bool found = false;
	for(int i=0;i<n-1;i++)
	{
		unordered_set<int> S;
		for(int j=i+1;j<n;j++)
		{
			int x = -(arr[i] + arr[j]);
			if(S.find(x) != S.end())
			{
				cout<<x<<' '<<arr[i]<<' '<<arr[j]<<endl;
				found = true;
			}
			else
				S.insert(arr[j]);
		}
	}
	if(found == false)
		cout<<"\nNo triplet with 0 sum";
}


void sorting(int *arr, int n)
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
			if(x+arr[l]+arr[r] == 0)
			{
				cout<<x<<' '<<arr[l]<<' '<<arr[r]<<endl;
				l++;
				r--;
				found = true;
			}
			else if(x+arr[l]+arr[r] < 0)
				l++;
			else
				r--;
		}
	}
	if(found == false)
		cout<<"\nNo triplet with 0 sum";
}



int main()
{
	int arr[] = {0,-1,2,-3,1};
	int n = sizeof(arr)/sizeof(int);

	//bruteforce(arr,n);
	//hashing(arr,n);
	sorting(arr,n);

	return 0;
}
