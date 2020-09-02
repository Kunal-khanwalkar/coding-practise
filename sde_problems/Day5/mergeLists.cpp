#include<iostream>
#include"linkedlist.h"
using namespace std;


int main()
{

	list<int> L1;
	for(int i=0;i<10;i+=2)
		L1.push(i);
	L1.traverse();		

	list<int> L2;
	for(int i=1;i<10;i+=2)
		L2.push(i);
	L2.traverse();		


	

	return 0;
}