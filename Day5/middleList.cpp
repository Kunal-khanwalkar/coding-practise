#include<iostream>
#include"linkedlist.h"
using namespace std;



void findMiddle(node<int>* head)
{
	node<int>* doubleptr = head;
	node<int>* ptr = head;

	while(doubleptr != nullptr && doubleptr->next != nullptr)
	{
		doubleptr = doubleptr->next->next;
		ptr = ptr->next;
	}
	cout<<ptr->data;
}


void newMiddle(node<int>* head)
{
	int cnt=0;
	node<int>* mid = head;

	while(head!=nullptr)
	{
		if(cnt & 1)
			mid = mid->next;
		cnt++;
		head = head->next;
	}
	if(mid!=nullptr)
		cout<<mid->data;
}

int main()
{

	list<int> L;
	for(int i=0;i<10;i++)
		L.push(i+1);
	L.traverse();		
	
	//findMiddle(L.head);
	newMiddle(L.head);

	return 0;
}