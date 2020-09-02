#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int brute(int *x, int *y, int m, int n)
{
	int cnt = 0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(pow(x[i],y[j]) > pow(y[j],x[i]))
				cnt++;
	return cnt;
}


int countUtil(int x, int *y, int n, int *noY)
{
	if(x==0)
		return 0;
	if(x==1)
		return noY[0];

	int *idx = upper_bound(y,y+n,x);
	int ans = (y+n) - idx;

	ans += (noY[0] + noY[1]);

	if(x==2)
		ans -= (noY[3] + noY[4]);
	if(x==3)
		ans += noY[2];

	return ans;
}

int countPairs(int *x, int *y, int m, int n)
{
	int noY[5] = {0};
	for(int i=0;i<n;i++)
		if(y[i] < 5)
			noY[y[i]]++;

	sort(y,y+n);

	int pairs = 0;

	for(int i=0;i<m;i++)
		pairs += countUtil(x[i],y,n,noY);

	return pairs;
}


int main()
{
	int x[] = {2,1,6};
	int y[] = {1,5};
	int m = 3;
	int n = 2;

	cout<<"\nTotal pairs: "<<countPairs(x,y,m,n);
	return 0;
}