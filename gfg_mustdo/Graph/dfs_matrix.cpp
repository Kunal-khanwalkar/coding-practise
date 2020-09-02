#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;



void DFSUtil(vector<vector<int>> mat, int V, set<int> &visited, int start)
{
	visited.insert(start);
	cout<<start<<' ';

	for(int i=0;i<V;i++)
		if(mat[start][i]==1 && !visited.count(i))
			DFSUtil(mat,V,visited,i);
}

void DFS(vector<vector<int>> mat, int V)
{
	set<int> visited;
	DFSUtil(mat,V,visited,0);
}



void DFS_iter(vector<vector<int>> mat, int V)
{
	set<int> visited;
	stack<int> s;
	s.push(0);

	while(!s.empty())
	{
		int v = s.top();
		s.pop();

		if(!visited.count(v))
		{
			cout<<v<<' ';
			visited.insert(v);
		}

		for(int i=0;i<V;i++)
			if(mat[v][i]==1 && !visited.count(i))
				s.push(i);
	}
}


int main()
{
	int V=4;
	vector<vector<int>> mat(V, vector<int>(V));

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


	cout<<"\nDFS: ";
	DFS(mat,V);

	cout<<"\nDFS: ";
	DFS_iter(mat,V);

	return 0;
}