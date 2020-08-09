#include<iostream>
#include<list>
#include<set>
#include<queue>
using namespace std;



void BFS(list<int> *adj, int V)
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

		for(auto itr: adj[v])
			if(!visited.count(itr))
				q.push(itr);
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

	cout<<"\nBFS: ";
	BFS(adj,V);

	return 0;
}