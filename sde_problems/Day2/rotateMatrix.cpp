#include<iostream>
using namespace std;


void rotate(int image[4][4], int m, int n, int destination[4][4])
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			destination[j][m-1-i] = image[i][j];
		}
	}
}



void squarerotate(int image[4][4], int n)
{
	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-1-i;j++)
		{
			int temp = image[i][j];
			image[i][j] = image[j][n-1-i];
			image[j][n-1-i] = image[n-1-i][n-1-j];
			image[n-1-i][n-1-j] = image[n-1-j][i];
			image[n-1-j][i] = temp;
		}
	}
}



int main()
{
	int image[4][4] = {{1,2,3,4},
						{5,6,7,8},
						{9,10,11,12},
						{13,14,15,16}};
	int m = 4;
	int n = 4;
	int destination[4][4];

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<image[i][j]<<' ';
		cout<<endl;
	}	
	cout<<endl;

	squarerotate(image,n);	

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<image[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}