#include<iostream>
#include<vector>
#include<set>
using namespace std;


int minDist(vector<int> &dist, set<int> &visited, int V)
{
	int min = INT_MAX, min_index;

	for(int i=0;i<V;i++)
		if(!visited.count(i) && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}

	return min_index;
}



void dijkstra(vector<vector<int>> mat, int V, int src)
{
	vector<int> dist(V,INT_MAX);
	set<int> visited;

	dist[src] = 0;
	
	for(int v=0;v<V-1;v++)
	{
		int d = minDist(dist,visited,V);
		visited.insert(d);

		for(int i=0;i<V;i++)
		{
			if(!visited.count(i) && mat[d][i] && dist[d] != INT_MAX)
				if(dist[i] > dist[d] + mat[d][i])
					dist[i] = dist[d] + mat[d][i];
		}
	}


	cout<<"\nVertex\tDistance from source\n";
	for(int i=0;i<V;i++)
		cout<<i<<'\t'<<dist[i]<<'\n';
}


int main()
{
	/*
	int V = 9;
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    */
	int V=5;
	int graph[V][V] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };   
	

    vector<vector<int>> mat;
    for(int i=0;i<V;i++)
    	mat.push_back(vector<int>(graph[i], graph[i] + sizeof(graph[i])/sizeof(int)));

    dijkstra(mat,V,0);

	return 0;
}