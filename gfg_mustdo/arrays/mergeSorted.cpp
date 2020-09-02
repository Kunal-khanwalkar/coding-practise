#include<iostream>
#include<algorithm>
using namespace std;


void extraSpace(int *ar1, int *ar2, int n1, int n2)
{
	int temp[n1 + n2];

	for(int i=0;i<n1;i++)
		temp[i] = ar1[i];
	for(int i=0;i<n2;i++)
		temp[i+n1] = ar2[i];

	sort(temp,temp+n1+n1);

	for(int i=0;i<n1;i++)
		ar1[i] = temp[i];
	for(int i=0;i<n2;i++)
		ar2[i] = temp[n1+i];
}


void continuousSwap(int *ar1, int *ar2, int n1, int n2)
{
	for(int i=n2-1; i>=0; i--)
	{
		int last = ar1[n1-1], int j = n1-2;
		while(ar1[j] > ar2[i] && j>=0)
		{
			ar1[j+1] = ar1[j];
			j--;
		}
		if(j!=n1-2 || last>ar2[i])
		{
			ar1[j+1] = ar2[i];
			ar2[i] = last;
		}
	}
}


int main()
{
	int ar1[] = {1,5,9,10,12,15};
	int size1 = sizeof(ar1)/sizeof(int);
	int ar2[] = {2,3,8,13};
	int size2 = sizeof(ar2)/sizeof(int);

	continuousSwap(ar1,ar2,size1,size2);

	cout<<"\nMerged array: ";
	for (int i=0;i<size1;i++)
		cout<<ar1[i]<<' ';
	for (int i=0;i<size2;i++)
		cout<<ar2[i]<<' ';

	return 0;
}