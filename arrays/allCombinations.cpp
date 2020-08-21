#include<iostream>
#include<vector>
using namespace std;



void print(vector<vector<int>> arr)
{
	int n = arr.size();

	int *indices = new int[n];

	for(int i=0;i<n;i++)
		indices[i] = 0;

	while(true)
	{
		for(int i=0;i<n;i++)
			cout<<arr[i][indices[i]]<<' ';
		cout<<'\n';

		int next = n-1;
		while(next>=0 && (indices[next] + 1 >= arr[next].size()))
			next--;

		if(next<0)
			return;

		indices[next]++;
		for(int i=next+1;i<n;i++)
			indices[i] = 0;
	}
}



int main()
{
    vector<vector<int>> arr(3, vector<int>(0, 0)); 
  
    // now entering data 
    // [[1, 2, 3], [4], [5, 6]] 
    arr[0].push_back(1); 
    arr[0].push_back(2); 
    arr[0].push_back(3); 
    arr[1].push_back(4); 
    arr[2].push_back(5); 
    arr[2].push_back(6); 

    print(arr);

	return 0;
}