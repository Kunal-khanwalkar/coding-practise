#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(const pair<int,int> &m1, const pair<int,int> &m2)
{
	return (m1.second < m2.second);
}


void maxMeetings(vector<pair<int,int>> meetings)
{
	int n = meetings.size();
		
	sort(meetings.begin(), meetings.end() , compare);		

	vector<pair<int,int>> final;

	final.push_back({meetings[0].first, meetings[0].second});
	int time_limit = meetings[0].second;

	for(int i=1;i<n;i++)
	{
		if(meetings[i].first >= time_limit)
		{
			final.push_back({meetings[i].first, meetings[i].second});
			time_limit = meetings[i].second;
		}		
	}

	cout<<"\nMeetings selected: ";
	for(int i=0;i<final.size();i++)
		cout<<'('<<final[i].first<<','<<final[i].second<<") ";
}

int main()
{
	vector<pair<int,int>> meetings;
	meetings.push_back({0,6});
	meetings.push_back({3,4});
	meetings.push_back({1,2});
	meetings.push_back({5,7});
	meetings.push_back({5,9});
	meetings.push_back({8,9});

	maxMeetings(meetings);

	return 0;
}