#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;



void BFS(vector<vector<int>> mat, int V)
{
	set<int> visited;
	queue<int> q;
	q.push(0);

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		if(!visited.count(v))
		{
			cout<<v<<' ';
			visited.insert(v);
		}

		for(int i=0;i<V;i++)
			if(mat[v][i]==1 && !visited.count(i))
				q.push(i);
	}
}


int main()
{
	int V=4;
	vector<vector<int>> mat(V,vector<int>(V));

	mat[0][1] = 1;
	mat[0][2] = 1;
	mat[1][2] = 1;
	mat[2][0] = 1;
	mat[2][3] = 1;
	mat[3][3] = 1;

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<mat[i][j]<<' ';
		cout<<'\n';
	}

	cout<<"\nBFS: ";
	BFS(mat,V);

	return 0;
}