#include<iostream>
#include<list>
#include<set>
#include<stack>
using namespace std;


void DFSUtil(list<int> *adj, int V, set<int> &visited, int start)
{
	visited.insert(start);
	cout<<start<<' ';

	for(auto itr=adj[start].begin();itr!=adj[start].end();itr++)
		if(!visited.count(*itr))
			DFSUtil(adj,V,visited,*itr);
}


void DFS(list<int> *adj, int V)
{
	set<int> visited;

	DFSUtil(adj,V,visited,0);
}



void DFS_iter(list<int> *adj, int V)
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

		for(auto itr=adj[v].begin(); itr!=adj[v].end(); itr++)
			if(!visited.count(*itr))
				s.push(*itr);
	}
}



int main()
{
	int V = 4;
	list<int> *adj = new list<int>[V];

	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);

	for(int i=0;i<V;i++)
	{
		for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
			cout<<*itr<<' ';
		cout<<'\n';
	}

	cout<<"\nDFS: ";
	DFS(adj,V);

	cout<<"\nDFS: ";
	DFS_iter(adj,V);

	return 0;
}