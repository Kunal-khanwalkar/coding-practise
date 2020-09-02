#include<iostream>
#include<cstring>
using namespace std;

const int V = 5;


void DFS(bool graph[][V], bool visited[V], int n, int v, int start, int &count)
{
	visited[v] = true;
	if(n==0)
	{
		visited[v] = false;
		if(graph[v][start])	
			count++;
		return;
	}

	for(int i=0;i<V;i++)
		if(!visited[i] && graph[v][i])
			DFS(graph,visited,n-1,i,start,count);
		
	visited[v] = false;
}



int countCycles(bool graph[][V], int n)
{
	bool visited[V];
	memset(visited,0,sizeof(visited));

	int count=0;
	for(int i=0;i<V;i++)
	{
		DFS(graph,visited,n-1,i,i,count);
		visited[i] = true;
	}

	return count;
}




int main()
{
    bool graph[][V] = {{0, 1, 0, 0, 0}, 
                      {0, 0, 1, 0, 0}, 
                      {0, 0, 0, 1, 0}, 
                      {1, 0, 0, 0, 1}, 
                      {0, 1, 0, 0, 0}}; 
    int n = 4; 
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n); 

	return 0;
}