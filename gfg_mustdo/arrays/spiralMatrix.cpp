#include<iostream>
using namespace std;



void spiralMatrix(int arr[3][6], int r, int c)
{
	int i, k=0, l=0;

	while(k<r && l<c)
	{
		for(i=l; i<c; i++)
			cout<<arr[k][i]<<' ';
		k++;

		for(i=k; i<r; i++)
			cout<<arr[i][c-1]<<' ';
		c--;

		if(k<r)
		{
			for(i=c-1; i>=l; i--)
				cout<<arr[r-1][i]<<' ';
			r--;
		}

		if(l<c)
		{
			for(i=r-1; i>=k; i--)
				cout<<arr[i][l]<<' ';
			l++;
		}
	}

}



void recursivePrint(int arr[3][6], int i, int j, int r, int c)
{
	if(i>=r || j>=c)
		return;

	for(int k=i;k<c;k++)
		cout<<arr[i][k]<<' ';
	for(int k=i+1;k<r;k++)
		cout<<arr[k][c-1]<<' ';
	if((r-1) != i)
		for(int k=c-2;k>=j;k--)
			cout<<arr[r-1][k]<<' ';
	if((c-1) != j)
		for(int k=r-2;k>=i;k--)
			cout<<arr[k][j]<<' ';

	recursivePrint(arr,i+1,j+1,r-1,c-1);
}



int main()
{
	int r = 3, c = 6;
    int arr[3][6] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 

    recursivePrint(arr,0,0,r,c);

	return 0;
}