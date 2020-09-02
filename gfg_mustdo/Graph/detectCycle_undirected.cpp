#include<iostream>
#include<list>
#include<set>
using namespace std;



bool isCyclicUtil(list<int> *adj, int V, set<int> &visited, int start, int parent)
{
	visited.insert(start);

	for(auto itr: adj[start])
		if(!visited.count(itr) && isCyclicUtil(adj,V,visited,itr,start))
			return true;
		else if(itr != parent)
			return true;
	
	return false;
}


bool isCyclic(list<int> *adj, int V)
{
	set<int> visited;
	for(int i=0;i<V;i++)
		if(!visited.count(i) && isCyclicUtil(adj,V,visited,i,-1))			
			return true;

	return false;
}




int main()
{
	int V=4;
	list<int> *adj = new list<int>[V];

	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);	
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(3);

	for(int i=0;i<V;i++)
	{
		cout<<i;
		for(auto itr: adj[i])
			cout<<"->"<<itr;
		cout<<'\n';
	}


	if(isCyclic(adj,V))
		cout<<"\nCycle";
	else
		cout<<"\nNo cycle";

	return 0;
}