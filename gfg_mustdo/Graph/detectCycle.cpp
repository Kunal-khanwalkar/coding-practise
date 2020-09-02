#include<iostream>
#include<list>
#include<set>
using namespace std;



bool isCyclicUtil(list<int> *adj, int V, set<int> &visited, set<int> &recStack, int v)
{
	if(!visited.count(v))
	{
		visited.insert(v);
		recStack.insert(v);

		for(auto itr: adj[v])
			if(!visited.count(itr) && isCyclicUtil(adj,V,visited,recStack,itr))
				return true;
			else if(recStack.count(itr))
				return true;
	}
	recStack.erase(v);
	return false;
}


bool cycleExists(list<int> *adj, int V)
{
	set<int> visited;
	set<int> recStack;

	for(int i=0;i<V;i++)
		if(isCyclicUtil(adj,V,visited,recStack,i))
			return true;
	return false;
}


int main()
{
	int V=4;
	list<int> *adj = new list<int>[V];

	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);

	for(int i=0;i<V;i++)
	{
		cout<<i;
		for(auto itr: adj[i])
			cout<<"->"<<itr;
		cout<<'\n';
	}

	if(cycleExists(adj,V))
		cout<<"\nContains Cycle";
	else
		cout<<"\nNo cycle";

	return 0;
}