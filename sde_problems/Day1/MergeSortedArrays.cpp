#include<iostream>
#include<algorithm>
using namespace std;



void myway(int *ar1, int size1, int *ar2, int size2)
{
	int temp[size1+size2];

	for(int i=0;i<size1;i++)
		temp[i] = ar1[i];
	for(int i=0;i<size2;i++)
		temp[size1+i] = ar2[i];

	sort(temp, temp + size1 + size2);	

	for(int i=0;i<size1;i++)
		ar1[i] = temp[i];
	for(int i=0;i<size2;i++)
		ar2[i] = temp[i + size1];
}

void merge(int *ar1, int size1, int *ar2, int size2)
{
	for(int i=size2-1;i>=0;i--)
	{
		int j = size1-2, last = ar1[size1-1];
		while(ar1[j] > ar2[i] && j>=0)
		{
			ar1[j+1] = ar1[j];
			j--;
		}
		if(j!=size1-2 || last>ar2[i])
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

	merge(ar1,size1,ar2,size2);

	cout<<"\nMerged array: ";
	for (int i=0;i<size1;i++)
		cout<<ar1[i]<<' ';
	for (int i=0;i<size2;i++)
		cout<<ar2[i]<<' ';

	return 0;
}