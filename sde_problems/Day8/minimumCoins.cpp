#include<iostream>
using namespace std;


int mcoins(int *coins, int n, int V)
{
	if (V==0)
		return 0;
	int res = INT_MAX;

	for(int i=0;i<n;i++)
	{
		if(coins[i] <= V)
		{
			int sub_res = mcoins(coins, n, V - coins[i]);
			if(sub_res != INT_MAX && sub_res+1 < res)
				res = sub_res + 1;
		}
	}

	return res;
}


int dp(int *coins, int n, int V)
{
	int table[V+1];
	table[0] = 0;

	for(int i=1;i<=V;i++)
		table[i] = INT_MAX;

	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j] <= i)
			{
				int sub_res = table[i-coins[j]];
				if(sub_res != INT_MAX && sub_res+1 < table[i])
					table[i] = sub_res + 1;
			}
		}
	}

	return table[V];
}


int main()
{
	int coins[] = {9,6,5,1};
	int n = sizeof(coins)/sizeof(int);
	int V = 11;

	cout<<"\nMinimum coins: "<<mcoins(coins,n,V);

	return 0;
}