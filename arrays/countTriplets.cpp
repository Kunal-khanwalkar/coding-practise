#include<iostream>
#include<unordered_set>
using namespace std;



void bruteForce(int *arr, int n)
{
	int cnt = 0;
	for(int i=0;i<n-2;i++)	
		for(int j=i+1;j<n-1;j++)		
			for(int k=j+1;k<n;k++)
			{
				if(arr[i] + arr[j] == arr[k] || arr[i] + arr[k] == arr[j] || arr[k] + arr[j] == arr[i])
					cnt++;
			}		

	cout<<"\nNumber of triplets: "<<cnt;
}


void hashing(int *arr, int n)
{
	int cnt = 0;
	for(int i=0;i<n-1;i++)	
	{
		unordered_set<int> S;
		for(int j=i+1;j<n;j++)
		{
			int x = -(arr[i] + arr[j]);
			if(S.count(x))
				cnt++;
			else
				S.insert(arr[j]);
		}
	}

	cout<<"\nNumber of triplets: "<<cnt;
}


void countWays(int *arr, int n)
{
	int max_val = 0;
	for(int i=0;i<n;i++)
		max_val = max(max_val,arr[i]);

	int freq[max_val + 1] = {0};
	for(int i=0;i<n;i++)
		freq[arr[i]]++;

	int ans = 0;
	ans += freq[0] * (freq[0]-1) * (freq[0]-2) / 6;

	for(int i=1;i<=max_val;i++)
		ans += freq[0] * freq[i] *(freq[i]-1)/2;

	for(int i=1;i<=max_val;i++)
		ans += freq[i] * (freq[i]-1)/2 * freq[2*i];

	for(int i=1;i<=max_val;i++)
		for(int j=i+1;i+j<=max_val;j++)
			ans += freq[i] * freq[j] * freq[i+j];

	cout<<"\nNumber of triplets: "<<ans;
}


int main()
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(int);	

	countWays(arr,n);

	return 0;
}