#include<iostream>
#include"tree.h"


void rightView(node<int>* root)
{
	if(!root)
		return;

	queue<node<int>*> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();
		for(int i=1;i<=n;i++)
		{
			node<int>* temp = q.front();
			q.pop();

			if(i==n)
				cout<<temp->data<<' ';
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}


void rightViewRecursive(node<int>* root, int level, int *max_level)
{
	if(!root)
		return;
	if(*max_level < level)
	{
		cout<<root->data<<' ';
		*max_level = level;
	}

	rightViewRecursive(root->right,level+1,max_level);
	rightViewRecursive(root->left,level+1,max_level);
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder Traversal: ";
	t.inorder(root);

	cout<<"\nRight view: ";
	rightView(root);

	cout<<"\nRight view Recursive: ";
	int max_level = 0;
	rightViewRecursive(root,1,&max_level);

	return 0;
}