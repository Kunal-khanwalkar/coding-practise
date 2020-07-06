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
				if(arr[i]+arr[j] == arr[k] || arr[i]+arr[k] == arr[j] || arr[j]+arr[k] == arr[i])
				{
					cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<endl;
					found = true;					
				}
			}
	if(found == false)
		cout<<"\nno such triplet";
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
		cout<<"\nno such triplet";
}


void sorting(int *arr, int n)
{
	sort(arr,arr+n);
	bool found = false;

	for(int i=n-1;i>=0;i--)
	{
		int l = 0;
		int r = i-1;		
		while(l<r)
		{
			if(arr[i] == arr[l] + arr[r])
			{
				cout<<arr[i]<<' '<<arr[l]<<' '<<arr[r]<<endl;
				l++;
				r--;
				found = true;
			}
			else if(arr[i] > arr[l] + arr[r])
				l++;
			else
				r--;
		}
	}
	if(found == false)
		cout<<"\nno such triplet";
}



int main()
{
	int arr[] = {5, 32, 1, 7, 10, 50, 19, 21, 2};
	int n = sizeof(arr)/sizeof(int);

	//bruteforce(arr,n);
	//hashing(arr,n);
	sorting(arr,n);

	return 0;
}
