#include<iostream>
#include"tree.h"
using namespace std;


bool identical(node<int>* root1, node<int>* root2)
{
	if(!root1 && !root2)
		return false;

	if(root1 && root2)
	{
		return (root1->data == root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right));
	}

	return false;
}



int main()
{	
	cout<<"\nMake tree 1\n";
	tree<int> t1;
	node<int>* root1 = t1.returnroot();
	root1 = t1.create();

	cout<<"\nMake tree 2\n";
	tree<int> t2;
	node<int>* root2 = t2.returnroot();
	root2 = t2.create();

	cout<<"\nInorder traversal tree 1: ";
	t1.inorder(root1);
	cout<<"\nInorder traversal tree 2: ";
	t2.inorder(root2);

	if(identical(root1,root2))
		cout<<"\nThey identical";
	else
		cout<<"\nNot identical";

	return 0;
}