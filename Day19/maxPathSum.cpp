#include<iostream>
#include"tree.h"
using namespace std;


int findMax(node<int>* root, int &res)
{
	if(!root)
		return 0;

	int l = findMax(root->left, res);
	int r = findMax(root->right, res);

	int max_now = max(max(l,r) + root->data, root->data);
	int max_top = max(max_now, l+r+root->data);

	res = max(res, max_top);

	return max_top;
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	int res = INT_MIN;	
	cout<<"\nMax Sum: "<<findMax(root,res);	

	return 0;
}