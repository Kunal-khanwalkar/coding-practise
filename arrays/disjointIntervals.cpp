#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;



bool compare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}

void disjoint(vector<pair<int,int>> intervals)
{
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), compare);

	cout<<intervals[0].first<<','<<intervals[0].second<<' ';
	int r1 = intervals[0].second;

	for(int i=1;i<n;i++)
	{
		int l2 = intervals[i].first;
		int r2 = intervals[i].second;
		if(l2 > r1)
		{
			cout<<l2<<','<<r2<<' ';
			r1 = r2;
		}
	}

}



int main()
{
    vector<pair<int, int> > intervals = { { 1, 4 }, 
                                          { 2, 3 }, 
                                          { 4, 6 }, 
                                          { 8, 9 } }; 

    disjoint(intervals);
	return 0;
}