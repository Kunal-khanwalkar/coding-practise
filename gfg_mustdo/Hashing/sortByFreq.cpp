#include<iostream>
#include<utility>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;



bool compare(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
	if(p1.second.second != p2.second.second)
		return (p1.second.second > p2.second.second);
	else
		return (p1.second.first < p2.second.first);
}


void sortFreq(int *arr, int n)
{
	map<int,pair<int,int>> mp;
	for(int i=0;i<n;i++)
	{
		if(mp.count(arr[i]))
			mp[arr[i]].second++;
		else
			mp[arr[i]] = {i,1};
	}


	vector<pair<int,pair<int,int>>> v;
	for(auto itr=mp.begin();itr!=mp.end();itr++)
		v.push_back({itr->first,itr->second});

	sort(v.begin(), v.end(),compare);
	
	int i=0;
	for(auto itr=v.begin();itr!=v.end();itr++)	
		for(int j=0;j<itr->second.second;j++)
			arr[i++] = itr->first;	
			
}	





int main()
{
	int arr[] = {1,5,3,4,3,7,5,3,2};
	int n = sizeof(arr)/sizeof(int);

	sortFreq(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	return 0;
}