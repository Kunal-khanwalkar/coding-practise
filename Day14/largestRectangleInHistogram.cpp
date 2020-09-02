#include<iostream>
#include<stack>
using namespace std;


int maxArea(int *hist, int n)
{
	stack<int> s;
	int i = 0, max_area = 0;
	int tp, area_with_top;	

	while(i<n)
	{
		if(s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		else
		{
			tp = s.top();
			s.pop();
			area_with_top = hist[tp] * (s.empty() ? i : i-s.top()-1);

			if(max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while(!s.empty())
	{
		tp = s.top();
		s.pop();

		area_with_top = hist[tp] * (s.empty() ? i : i-s.top()-1);		

		if(max_area < area_with_top)
				max_area = area_with_top;
	}

	return max_area;
}





int main()
{
	int hist[] = {6,2,5,4,5,1,6};
	int n = sizeof(hist)/sizeof(int);

	cout<<"\nMax area: "<<maxArea(hist,n);

	return 0;
}