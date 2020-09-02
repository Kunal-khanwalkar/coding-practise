#include<iostream>
using namespace std;


void flipZeroes(int *arr,int n,int m)
{
	int wL=0,wR=0;
	int bestL=0, bestWindow=0;
	int zeroCount=0;

	while(wR < n)
	{
		if(zeroCount <= m)
		{
			if(arr[wR] == 0)
				zeroCount++;
			wR++;
		}
		else if(zeroCount > m)
		{
			if(arr[wL]==0)
				zeroCount--;
			wL++;
		}
		if((wR-wL > bestWindow) && (zeroCount <= m))
		{
			bestWindow = wR-wL;
			bestL = wL;
		}
	}

	for(int i=0;i<bestWindow;i++)
		if(arr[bestL + i] == 0)
			cout<<bestL+i<<' ';
}





int main()
{
	int arr[] = {1,0,0,1,1,0,1,0,1,1};
	int n = sizeof(arr)/sizeof(int);
	int m = 2;

	cout<<"\nIndexes of zeroes flipped: ";
	flipZeroes(arr,n,m);

	return 0;
}