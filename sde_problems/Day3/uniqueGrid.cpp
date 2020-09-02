#include<iostream>
using namespace std;


int paths(int arr[3][3], int n)
{
	int temp[3][3];

	if(arr[0][0] == 0)	
		temp[0][0]=1;

	for(int i=1;i<n;i++)
		if(arr[i][0]==0)
			temp[i][0] = temp[i-1][0];

	for(int i=1;i<n;i++)
		if(arr[0][i]==0)
			temp[0][i] = temp[0][i-1];

	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			if(arr[i][j]==0)
				temp[i][j] = temp[i-1][j] + temp[i][j-1];

	return temp[n-1][n-1];	
}


int uniquePaths(int n)
{
	int dp[n][n];
	for(int i=0;i<n;i++)
	{
		dp[0][i] = 1;
		dp[i][0] = 1;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[n-1][n-1];
}



int main()
{
	int arr[3][3] = {{0,0,0},
					{0,1,0},
					{0,0,0}};
	int n = sizeof(arr)/sizeof(arr[0]);


	cout<<"\nUnique paths: "<<paths(arr,n);
	return 0;
}