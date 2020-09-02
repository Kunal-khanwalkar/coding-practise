#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


void findroot(double x, int n)
{
	double low,high;

	if(x>=0 && x<=1)
	{
		low = x;
		high = 1;		
	}
	else
	{
		low = 1;
		high = x;
	}

	double epsilon = 0.00000001;

	double guess = (low + high) / 2;
	while(abs((pow(guess,n)) - x) >= epsilon)
	{
		if(pow(guess,n) > x)
			high = guess;
		else
			low = guess;
		guess = (low + high) / 2;
	}

	cout<<"\nRoot: "<<fixed<<setprecision(16)<<guess;
}


int main()
{
	double x = 5;
	int n = 2;

	findroot(x,n);

	return 0;
}