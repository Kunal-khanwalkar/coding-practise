#include<iostream>
#include"tree.h"
using namespace std;


int diameter(node<int>* root, tree<int>* t)
{
	if(!root)
		return 0;

	int l = t->depth(root->left);
	int r = t->depth(root->right);

	int ldia = diameter(root->left,t);
	int rdia = diameter(root->right,t);

	return max(l + r + 1, max(ldia,rdia));
}


int diameterOpt(node<int>* root, int *height)
{
	int lh=0, rh=0;
	int ldia=0, rdia=0;

	if(!root)
	{
		*height = 0;
		return 0;
	}

	ldia = diameterOpt(root->left,&lh);
	rdia = diameterOpt(root->right,&rh);

	*height = max(lh,rh) + 1;

	return max(lh+rh+1, max(ldia,rdia));
}

int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	int height=0;
	cout<<"\nDiameter of tree: "<<diameterOpt(root,&height);
	return 0;
}