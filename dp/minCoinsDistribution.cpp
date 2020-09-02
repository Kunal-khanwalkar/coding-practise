#include<iostream>
using namespace std;



void minCoinsRequired(int arr[], bool visited[], int &n, int V)
{
	if(V==0)
	{
		n = 0;
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(!visited[i] && arr[i] <= V)
		{
			visited[i] = true;
			minCoinsRequired(arr,visited,n,V);
		}
	}

}



bool distribution_possible(int arr[], int n)
{
	bool visited[n];
	int total_amount = 0;

	for(int i=0;i<n;i++)
	{
		total_amount += arr[i];
		visited[i] = false;
	}

	int distribution_amount = total_amount/3;

	for(int i=0;i<3;i++)
	{
		int pass = n;
		minCoinsRequired(arr,visited,pass,distribution_amount);
	}

	for(int i=0;i<n;i++)
		if(!visited[i])
			return false;

	return true;
}



int main()
{
	int arr[] = {1,2,3,2,2,3,2};
	int n = sizeof(arr)/sizeof(int);

	if(distribution_possible(arr,n))
		cout<<"\nPossible";
	else
		cout<<"\nNot Possible";

	return 0;
}