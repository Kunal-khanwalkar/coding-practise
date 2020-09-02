#include<iostream>
#include<set>
using namespace std;


int setMethod(int *arr, int n)
{
	set<int> S;
	for(int i=0;i<n;i++)	
		S.insert(arr[i]);	

	int i=0;
	for(auto itr=S.begin();itr!=S.end();itr++)
		arr[i++] = *itr;	

	return S.size();
}


int uniqueIndex(int *arr, int n)
{
	int j=0;

	for(int i=0;i<n;i++)
		if(arr[i] != arr[i+1])
			arr[j++] = arr[i];

	arr[j++] = arr[n-1];
	return j;
}



int main()
{
	int arr[] = {1,2,2,3,4,4,4,5,5};
	int n = sizeof(arr)/sizeof(int);

	cout<<"\nNew size of array: "<<uniqueIndex(arr,n)<<'\n';

	for(int i=0;i<5;i++)
		cout<<arr[i]<<' ';
}