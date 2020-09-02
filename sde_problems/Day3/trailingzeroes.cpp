#include<iostream>
using namespace std;


int tzeroes(int n)
{
	int cnt=0;

	for(int i=5;n/i>=1;i*=5)
	{
		cnt += n/i;
	}
	return cnt;
}


int main()
{
	int n = 100;
	cout<<"\nTrailing zeroes: "<<tzeroes(n);

	return 0;
}