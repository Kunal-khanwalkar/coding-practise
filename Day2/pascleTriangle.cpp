#include<iostream>
using namespace std;


int binomialCoefficient(int n, int k)
{
	int res = 1;
	if(k>n-k)
		k = n-k;
	for(int i=0;i<k;i++)
	{
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

void pascletriangle(int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<binomialCoefficient(i,j)<<' ';
		}
		cout<<endl;
	}
}




void printPascal(int n)
{
	int arr[n][n];
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==i || j==0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
}



void optimalSolution(int n)
{
	cout<<endl;
	for (int i=1;i<=n;i++)
	{
		int c=1;
		for(int j=1;j<=i;j++)
		{
			cout<<c<<' ';
			c = c*(i-j)/j;
		}
		cout<<endl;
	}
}


int main()
{
	cout<<"\nEnter size: ";
	int n;
	cin>>n;

	//pascletriangle(n);
	//printPascal(n);
	optimalSolution(n);

	return 0;
}