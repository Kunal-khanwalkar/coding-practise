#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;


int isSafe(vector<vector<int>> mat, int V, set<pair<int,int>> &visited, int i, int j)
{
	return (i>=0 && i<V && j>=0 && j<V && mat[i][j]==1 && !visited.count({i,j}));
}


void DFS(vector<vector<int>> mat, int V, set<pair<int,int>> &visited, int i, int j)
{
	static int rowno[] = {-1,-1,-1,0,0,1,1,1};
	static int colno[] = {-1,0,1,-1,1,-1,0,1};

	visited.insert({i,j});

	for(int k=0;k<8;k++)
		if(isSafe(mat,V,visited,i+rowno[k],j+colno[k]))
			DFS(mat,V,visited,i+rowno[k],j+colno[k]);
}


int countIslands(vector<vector<int>> mat, int V)
{
	set<pair<int,int>> visited;

	int cnt=0;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if(mat[i][j]==1 && !visited.count({i,j}))
			{
				DFS(mat,V,visited,i,j);
				cnt++;
			}
	return cnt;
}



int main()
{
	int V=5;
	int graph[V][V] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };   
	
    vector<vector<int>> mat;
    for(int i=0;i<V;i++)
    	mat.push_back(vector<int>(graph[i], graph[i] + sizeof(graph[i])/sizeof(int)));


    cout<<"\nNumber of islands: "<<countIslands(mat,V);

	return 0;
}