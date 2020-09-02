#include<iostream>
#include<queue>
#include<utility>
using namespace std;


bool issafe(int i, int j)
{
	if(i>=0 && i<3 && j>=0 && j<5)
		return true;
	return false;
}


int rotOranges(int matrix[3][5])
{
	bool changed = false;
	int no = 2;

	while(true)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<5;j++)
			{
				if(matrix[i][j] == no)
				{
					if(issafe(i+1,j) && matrix[i+1][j]==1)
					{
						matrix[i+1][j] = matrix[i][j] + 1;
						changed = true;
					}
					if(issafe(i,j+1) && matrix[i][j+1]==1)
					{
						matrix[i][j+1] = matrix[i][j] + 1;
						changed = true;
					}
					if(issafe(i-1,j) && matrix[i-1][j]==1)
					{
						matrix[i-1][j] = matrix[i][j] + 1;
						changed = true;
					}
					if(issafe(i,j-1) && matrix[i][j-1]==1)
					{
						matrix[i][j-1] = matrix[i][j-1] + 1;
						changed = true;
					}
				}
			}

		if(!changed)
			break;
		changed = false;
		no++;
	}

	for(int i=0;i<3;i++)
		for(int j=0;j<5;j++)
			if(matrix[i][j] == 1)
				return -1;

	return no-2;
}




int bfs(int matrix[3][5])
{
	queue<pair<int,int>> q;
	pair<int,int> temp;
	int ans = 0;

	for(int i=0;i<3;i++)
		for(int j=0;j<5;j++)
			if(matrix[i][j] == 2)
			{
				temp.first = i;
				temp.second = j;
				q.push(temp);
			}

	temp.first = -1;
	temp.second = -1;
	q.push(temp);

	while(!q.empty())
	{
		bool flag = false;

		while(q.front().first != -1 && q.front().second != -1)
		{
			temp = q.front();

			if(issafe(temp.first + 1, temp.second) && matrix[temp.first + 1][temp.second])
			{
				if(!flag)
				{
					ans++;
					flag = true;
				}
				matrix[temp.first + 1][temp.second] = 2;
				temp.first++;
				q.push(temp);
				temp.first--;
			}

			if(issafe(temp.first -1, temp.second) && matrix[temp.first - 1][temp.second])
			{
				if(!flag)
				{
					ans++;
					flag = true;
				}
				matrix[temp.first - 1][temp.second] = 2;
				temp.first--;
				q.push(temp);
				temp.first++;
			}

			if(issafe(temp.first, temp.second + 1) && matrix[temp.first][temp.second + 1])
			{
				if(!flag)
				{
					ans++;
					flag = true;
				}
				matrix[temp.first][temp.second + 1] = 2;
				temp.second++;
				q.push(temp);
				temp.second--;
			}

			if(issafe(temp.first, temp.second - 1) && matrix[temp.first + 1][temp.second - 1])
			{
				if(!flag)
				{
					ans++;
					flag = true;
				}
				matrix[temp.first][temp.second - 1] = 2;
				temp.first--;
				q.push(temp);
				temp.first++;
			}			

			q.pop();
		}
		
		q.pop();

		if(!q.empty())
		{
			temp.first = -1;
			temp.second = -1;
			q.push(temp);
		}

	}
	

	for(int i=0;i<3;i++)	
		for(int j=0;j<5;j++)
			if(matrix[i][j] == 1)			
				return -1;			
	return ans;
}




int main()
{
	int matrix[3][5] = {  {2,1,0,2,1},
						{1,0,1,2,1},
						{1,0,0,2,1}};
	cout<<"\nMax Time: "<<bfs(matrix);

	return 0;
}