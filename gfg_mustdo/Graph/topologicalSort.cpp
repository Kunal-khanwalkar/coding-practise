#include<iostream>
#include<list>
#include<stack>
#include<set>
using namespace std;


void topoSortUtil(list<int> *adj, int V, set<int> &visited, stack<int> &s, int v)
{
	visited.insert(v);

	for(auto itr: adj[v])
		if(!visited.count(itr))
			topoSortUtil(adj,V,visited,s,itr);
	s.push(v);
}


void topoSort(list<int> *adj, int V)
{
	stack<int> s;
	set<int> visited;

	for(int i=0;i<V;i++)
		if(!visited.count(i))
			topoSortUtil(adj,V,visited,s,i);


	while(!s.empty())
	{
		cout<<s.top()<<' ';
		s.pop();
	}
}	




int main()
{
	int V=6;
	list<int> *adj = new list<int>[V];

	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);
	
	for(int i=0;i<V;i++)
	{
		cout<<i;
		for(auto itr: adj[i])
			cout<<"->"<<itr;
		cout<<'\n';
	}

	cout<<"\nTopological sort: ";
	topoSort(adj,V);

	return 0;
}