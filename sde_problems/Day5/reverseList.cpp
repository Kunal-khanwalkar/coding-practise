#include<iostream>
#include"linkedlist.h"
using namespace std;


node<int>* reverseList(node<int>* head)
{	
	node<int> *prev = nullptr;
	node<int> *curr = head;
	node<int> *next = nullptr;	

	while(curr!=nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

node<int>* recursiveReverse(node<int>* head)
{
	if(head==nullptr || head->next==nullptr)
		return head;

	node<int>* rest = recursiveReverse(head->next);
	head->next->next = head;
	head->next = nullptr;

	return rest;
}


int main()
{

	list<int> L;
	for(int i=0;i<10;i++)
		L.push(i+1);
	L.traverse();		

	//L.head = reverseList(L.head);
	L.head = recursiveReverse(L.head);
	
	L.traverse();

	return 0;
}