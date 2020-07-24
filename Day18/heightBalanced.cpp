#include<iostream>
#include"tree.h"
using namespace std;



bool isBalanced(node<int>* root, tree<int> t)
{
	int lh,rh;

	if(!root)
		return false;

	lh = t.depth(root->left);
	rh = t.depth(root->right);

	if (abs(lh-rh) <= 1 && isBalanced(root->left,t) && isBalanced(root->right,t))
		return true;

	return false;
}


bool isBalancedOpt(node<int>* root, int *height)
{
	int lh,rh;
	int l,r;

	if(!root)
	{
		*height = 0;
		return true;
	}

	l = isBalancedOpt(root->left,&lh);
	r = isBalancedOpt(root->right,&rh);

	*height = (lh > rh ? lh : rh) + 1;

	if (abs(lh-rh) >= 2)
		return false;

	return l && r;
}



int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	int max_height = 0;
	if(isBalancedOpt(root,&max_height))
		cout<<"\nTree is balanced";
	else
		cout<<"\nUnbalanced tree";

	return 0;
}