#include<iostream>
using namespace std;


int mypower(float n, int x)
{
	if(x==0)
		return 1;

	int result = 1;
	for(int i=1;i<=x;i++)
		result *= n;
	return result;
}


float logpower(float n, int x)
{
	float temp;
	if(x==0)
		return 1;
	temp = logpower(n,x/2);

	if(x%2==0)
		return temp*temp;
	else
	{
		if(x>0)
			return n*temp*temp;
		else
			return (temp*temp)/n;
	}

}


int main()
{
	float n = 2;
	int x = 5;

	cout<<mypower(n,x);

	cout<<'\n'<<logpower(n,x);

	return 0;
}