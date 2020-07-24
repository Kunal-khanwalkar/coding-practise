#include<iostream>
#include"tree.h"



void leftView(node<int>* root)
{
	if(root==nullptr)
		return;

	queue<node<int>*> q;
	q.push(root);
	node<int>* curr;

	while(!q.empty())
	{
		int nodeCount = q.size();
		int elements = q.size();
		while(nodeCount > 0)
		{
			curr = q.front();
			if(nodeCount == elements)
				cout<<curr->data<<' ';
			q.pop();
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
			nodeCount--;
		}		
	}
}


void leftViewUhhh(node<int>* root)
{
	if(root==nullptr)
		return;

	queue<node<int>*> q;
	q.push(root);
	node<int>* curr;

	while(!q.empty())
	{
		int n = q.size();		
		for(int i=1;i<=n;i++)
		{
			curr = q.front();
			q.pop();

			if(i==1)
				cout<<curr->data<<' ';
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
	}
}


void leftViewRecursive(node<int>* root, int level, int* maxlevel)
{
	if(root==nullptr)
		return;

	if(*maxlevel < level)
	{
		cout<<root->data<<' ';
		*maxlevel = level;
	}

	leftViewRecursive(root->left,level+1,maxlevel);
	leftViewRecursive(root->right,level+1,maxlevel);
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder Traversal: ";
	t.inorder(root);

	cout<<"\nLeft view: ";
	leftViewUhhh(root);


	cout<<"\nLeft view recursive: ";
	int maxlevel = 0;
	leftViewRecursive(root,1,&maxlevel);

	return 0;
}