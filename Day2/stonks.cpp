#include<iostream>
using namespace std;



int maxprofits(int *arr, int start, int end)
{
	if(end <= start)
		return 0;

	int profit = 0;

	for(int i=start; i<end; i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			if(arr[j] > arr[i])
			{
				int currprofit = arr[j] - arr[i] + maxprofits(arr,start,i-1) + maxprofits(arr,j+1,end);
				profit = max(profit,currprofit);
			}
		}
	}
	return profit;
}




void stockBuySell(int *arr, int n)
{
	if (n==1)
		return;

	int i=0;
	while(i<n-1)
	{
		while((i<n-1)&&(arr[i+1]<=arr[i]))
			i++;

		if(i==n-1)
			break;

		int buy = i++;

		while((i<n)&&(arr[i] >= arr[i-1]))
			i++;

		int sell = i-1;

		cout<<"\nBuy on day: "<<buy;
		cout<<"\nSell on day: "<<sell;
	}
}


int main()
{
	int arr[] = {100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(arr)/sizeof(int);

	//cout<<"\nMaximum profit: "<<maxprofits(arr,0,n-1);
	stockBuySell(arr,n);

	return 0;
}