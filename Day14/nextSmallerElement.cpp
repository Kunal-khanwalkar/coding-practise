#include<iostream>
#include<stack>
using namespace std;

void printNSE(int *arr, int n)
{
	int next;
	for(int i=0;i<n;i++)
	{
		next = -1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i] > arr[j])
			{
				next = arr[j];
				break;
			}			
		}
		cout<<arr[i]<<" -> "<<next<<endl;
	}
}


void stax(int *arr, int n)
{
	stack<int> s;
	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		while(!s.empty() && s.top() > arr[i])
		{
			cout<<s.top()<<" -> "<<arr[i]<<endl;
			s.pop();
		}
		s.push(arr[i]);
	}

	while(!s.empty())
	{
		cout<<s.top()<<" -> -1"<<endl;
		s.pop();
	}
}



int main()
{
	int arr[] = {11,13,21,3};
	int n = sizeof(arr)/sizeof(int);

	stax(arr,n);

	return 0;
}