#include<iostream>
#include<utility>
#include<algorithm>
#include<set>
using namespace std;



int minSwaps(int arr[], int n)
{
	pair<int,int> arrPos[n];
	for(int i=0;i<n;i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	sort(arrPos, arrPos + n);
	set<int> visited;
	int ans = 0;

	for(int i=0;i<n;i++)
	{
		if(visited.count(i) || arrPos[i].second == i)
			continue;

		int cycle_size=0;
		int j=i;
		while(!visited.count(j))
		{
			visited.insert(j);
			j = arrPos[j].second;
			cycle_size++;
		}

		if(cycle_size>0)
			ans += (cycle_size-1);
	}

	return ans;
}



int main()
{
	int arr[] = {2,4,5,1,3};
	int n = sizeof(arr)/sizeof(int);

	cout<<minSwaps(arr,n);

	return 0;
}