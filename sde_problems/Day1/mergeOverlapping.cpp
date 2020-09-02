#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;


void mergeIntervals(vector<pair<int,int>> &intervals, int size)
{
	sort(intervals.begin(), intervals.end());

	auto i=intervals.begin() + 1; 
	while(i!=intervals.end())
	{
		//cout<<i->first<<','<<i->second<<' ';
		if((i-1)->second >= i->second)
		{
			i = intervals.erase(i);
			continue;
		}
		else if((i-1)->second > i->first)
		{
			(i-1)->first = min((i-1)->first,i->first);
			(i-1)->second = i->second;
			i = intervals.erase(i);
			continue;
		}
		else
			i++;
	}
}

int main()
{
	vector<pair<int,int>> intervals {{1,3}, {2,4}, {5,7}, {6,8} }; //{6,8}, {1,9}, {2,4}, {4,7} 
	int size = intervals.size();

	mergeIntervals(intervals,size);
	
	for(auto i=intervals.begin(); i!=intervals.end(); i++)
		cout<<i->first<<','<<i->second<<' ';

	return 0;
}