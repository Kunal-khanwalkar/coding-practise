#include<iostream>
#include<unordered_map>
using namespace std;



int maxLen(int *arr, int n, int k)
{
	unordered_map<int,int> presum;

	int sum=0;
	int max_len=0;

	for(int i=0;i<n;i++)
	{
		sum += arr[i];		
		if(sum==k)
			max_len = i+1;

		if(presum.find(sum) == presum.end())
			presum[sum] = i;
		
		if(presum.find(sum-k) != presum.end())
		{
			max_len = max(max_len, i-presum[sum-k]);
		}
	}

	return max_len;
}


int main()
{
	int arr[] = {10,5,2,7,1,9};
	int n = sizeof(arr)/sizeof(int);
	int k = 15;

	cout<<"\nLongest ksum array: "<<maxLen(arr,n,k);

	return 0;
}