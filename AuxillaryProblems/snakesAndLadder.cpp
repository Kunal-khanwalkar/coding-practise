#include<iostream>
#include<utility>
#include<queue>
using namespace std;


int minThrow(int *moves, int N)
{
	bool *visited = new bool[N];
	for(int i=0;i<N;i++)
		visited[i] = false;

	//Vertex no, distance from source
	queue<pair<int,int>> q;

	visited[0] = true;	
	q.push({0,1});
	pair<int,int> qe;

	while(!q.empty())
	{
		qe = q.front();
		int v = qe.first;

		if(v==7)
			break;

		q.pop();

		for(int j=v+1; j<=(v+4) && j<N; j++)
		{
			if(!visited[j])
			{
				pair<int,int> a;
				a.second = qe.second + 1;
				visited[j] = true;

				if(moves[j] != -1)
					a.first = moves[j];
				else
					a.first = j;
				q.push(a);
			}
		}
	}

	return qe.second;
}



int main()
{
	int N = 16;
	int moves[N];
	for(int i=0;i<N;i++)
		moves[i] = -1;

	moves[1] = 5;
	moves[7] = 10;

	moves[8] = 2;
	moves[14] = 0;	

	cout<<"\nMinimum throws: "<<minThrow(moves,N);

	return 0;
}