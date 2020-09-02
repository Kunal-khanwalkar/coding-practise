#include<iostream>
using namespace std;
#define R 3
#define C 4


void zeroes(bool mat[R][C])
{
	bool row[R] = {0};
	bool col[C] = {0};
	int i,j;

	for(i=0;i<R;i++)	
		for(j=0;j<C;j++)		
			if(mat[i][j]==1)
			{
				row[i] = 1;
				col[j] = 1;
			}		

	for(i=0;i<R;i++)	
		for(j=0;j<C;j++)
			if(row[i]==1 || col[j]==1)
				mat[i][j] = 1;	


}



void modifyZeroes(bool mat[R][C])
{
	int i,j;
	bool row_flag = false;
	bool col_flag = false;

	for(i=0;i<R;i++)	
		for(j=0;j<C;j++)
		{
			if(i==0 && mat[i][j]==1)
				row_flag = true;
			if(j==0 && mat[i][j]==1)
				col_flag = true;

			if(mat[i][j]==1)
			{
				mat[0][j] = 1;
				mat[i][0] = 1;
			}
		}	


	for(i=1;i<R;i++)
		for(j=1;j<C;j++)
			if(mat[0][j]==1 || mat[i][0]==1)
				mat[i][j] = 1;

	if(row_flag = true)
		for(i=0;i<C;i++)
			mat[0][i] = 1;

	if(col_flag = true)
		for(i=0;i<R;i++)
			mat[i][0] = 1;
}



int main()
{
	bool mat[R][C] = {  {1,0,0,1},
						{0,0,1,0},
						{0,0,0,0}
					 };

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cout<<mat[i][j]<<' ';
		cout<<endl;
	}


	modifyZeroes(mat);

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cout<<mat[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}