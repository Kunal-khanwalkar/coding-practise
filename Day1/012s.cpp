#include<iostream>
using namespace std;

int main()
{
	int arr[] = {0,2,1,1,0,0};
	int size = sizeof(arr)/sizeof(int);
	int low = 0, mid = 0, high = size-1;

	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0: swap(arr[low++],arr[mid++]);
					break;
			case 1: mid++;
					break;
			case 2: swap(arr[high--],arr[mid]);
					break;
		}
	}


	for(int i=0;i<size;i++)
		cout<<arr[i]<<' ';

	return 0;
}