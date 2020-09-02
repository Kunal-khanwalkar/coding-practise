#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;



int first(int *arr, int low, int high, int x, int n)
{
	if(high >= low)
	{
		int mid = low + (high-low)/2;

		if((mid==0 || x>arr[mid-1]) && arr[mid] == x)
			return mid;

		if(x > arr[mid])
			return first(arr,(mid+1),high,x,n);

		return first(arr,low,(mid-1),x,n);
	}

	return -1;
}



void relativeSort(int *a1, int *a2, int m, int n)
{
	int temp[m], visited[m];
	for(int i=0;i<m;i++)
	{
		temp[i] = a1[i];
		visited[i] = 0;
	}

	sort(temp,temp+m);
	int index = 0;

	for(int i=0;i<n;i++)
	{
		int f = first(temp,0,m-1,a2[i],m);
		if(f==-1)
			continue;

		for(int j=f;(j<m && temp[j]==a2[i]);j++)
		{
			a1[index++] = temp[j];
			visited[j] = 1;			
		}
	}

	for(int i=0;i<m;i++)
		if(visited[i]==0)
			a1[index++] = temp[i];
}





void hashing(int *a1, int *a2, int m, int n)
{
	vector<int> v;

	map<int,int> mp;
	for(int i=0;i<m;i++)
		mp[a1[i]]++;

	for(int i=0;i<n;i++)
	{
		if(mp.count(a2[i]))
		{
			for(int j=0;j<mp[a2[i]];j++)
				v.push_back(a2[i]);
			mp.erase(a2[i]);
		}
	}

	for(auto itr=mp.begin();itr!=mp.end();itr++)
		v.push_back(itr->first);

	int i=0;
	for(auto itr=v.begin();itr!=v.end();itr++)
		a1[i++] = *itr;

}



int main()
{	
	int A1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 }; 
    int A2[] = { 2, 1, 8, 3 }; 
    int m = sizeof(A1) / sizeof(A1[0]); 
    int n = sizeof(A2) / sizeof(A2[0]); 

    hashing	(A1,A2,m,n);

    for(int i=0;i<m;i++)
    	cout<<A1[i]<<' ';

	return 0;
}