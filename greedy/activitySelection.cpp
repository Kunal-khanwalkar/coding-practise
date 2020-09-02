#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


bool compare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}

void activity(int *start, int *finish, int n)
{
	vector<pair<int,int>> activities;
	for(int i=0;i<n;i++)
		activities.push_back({start[i],finish[i]});

	sort(activities.begin(), activities.end(), compare);

	int i=0;
	cout<<activities[i].first<<','<<activities[i].second<<' ';
	for(int j=1;j<n;j++)
	{
		if(activities[j].first >= activities[i].second)
		{
			cout<<activities[j].first<<','<<activities[j].second<<' ';
			i = j;
		}
	}
}


int main()
{	
	int start[] = {1,3,0,5,8,5};
	int finish[] = {2,4,6,7,9,9};
	int n = sizeof(start)/sizeof(int);	

	activity(start,finish,n);

	return 0;
}