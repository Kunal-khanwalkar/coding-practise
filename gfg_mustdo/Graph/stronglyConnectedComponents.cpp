#include<iostream>
#include<list>
#include<set>
#include<stack>
using namespace std;


void DFS(list<int> *adj, int V, set<int> &visited, int v)
{
	visited.insert(v);
	cout<<v<<' ';

	for(auto itr:adj[v])
		if(!visited.count(itr))
			DFS(adj,V,visited,itr);
}



list<int>* getTranspose(list<int> *adj, int V)
{
	list<int> *trans = new list<int>[V];
	for(int i=0;i<V;i++)
	{
		for(auto itr: adj[i])
			trans[itr].push_back(i);
	}

	return trans;
}


void fillOrder(list<int> *adj, int V, set<int> &visited, stack<int> &s, int v)
{
	visited.insert(v);
	for(auto itr:adj[v])
		if(!visited.count(itr))
			fillOrder(adj,V,visited,s,itr);
	s.push(v);
}


void Components(list<int> *adj, int V)
{
	stack<int> s;
	set<int> visited;

	for(int i=0;i<V;i++)
		if(!visited.count(i))
			fillOrder(adj,V,visited,s,i);

	list<int> *transadj = getTranspose(adj,V);
	
	visited.clear();	

	while(!s.empty())
	{
		int v = s.top();
		s.pop();

		if(!visited.count(v))
		{
			DFS(transadj,V,visited,v);
			cout<<'\n';
		}
	}

}


int main()
{
	int V=5;
	list<int> *adj = new list<int>[V];

	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(1);
	adj[0].push_back(3);
	adj[3].push_back(4);

	cout<<"\nStrongly Connected Components: \n";
	Components(adj,V);

	return 0;
}