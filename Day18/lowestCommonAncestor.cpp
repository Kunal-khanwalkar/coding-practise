#include<iostream>
#include"tree.h"
using namespace std;



bool findpath(node<int>* root, vector<int> &path, int k)
{
	if(!root)
		return false;
	
	path.push_back(root->data);
	if(root->data == k)
		return true;

	if( (root->left && findpath(root->left, path, k)) || (root->right && findpath(root->right, path, k)))
		return true;

	path.pop_back();
	return false;
}


int findLCA(node<int>* root, int n1, int n2)
{
	vector<int> path1, path2;

	if(!findpath(root,path1,n1) || !findpath(root,path2,n2))
		return -1;

	int i;
	for (i = 0; i < path1.size() && i < path2.size(); ++i)	
		if(path1[i] != path2[i])
			break;	

	return path1[i-1];
}



node<int>* findLCAbetter(node<int>* root, int n1, int n2)
{
	if(!root)
		return nullptr;

	if(root->data == n1 || root->data == n2)
		return root;

	node<int>* lLCA = findLCAbetter(root->left, n1, n2);
	node<int>* rLCA = findLCAbetter(root->right, n1, n2);

	if(lLCA && rLCA)
		return root;

	return lLCA ? lLCA : rLCA;
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	//cout<<"\nLCA(4,5): "<<findLCA(root,4,5);

	node<int>* lca = findLCAbetter(root,4,5);
	cout<<"\nLCA(4,5): "<<lca->data;

	return 0;
}