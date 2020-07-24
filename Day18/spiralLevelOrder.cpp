#include<iostream>
#include"tree.h"
using namespace std;



void spiral(node<int>* root)
{
	if(!root)
		return;

	stack<node<int>*> s1;
	stack<node<int>*> s2;
	s1.push(root);	

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			node<int>* temp = s1.top();
			s1.pop();
			cout<<temp->data<<' ';

			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(!s2.empty())
		{
			node<int>* temp = s2.top();
			s2.pop();
			cout<<temp->data<<' ';

			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}		
	}
}


void spiralOut(node<int>* root)
{
	if(!root)
		return;

	stack<node<int>*>s1;
	stack<node<int>*>s2;
	s1.push(root);
	bool flag = false;

	while(!s1.empty() || !s2.empty())
	{
		flag = !flag;

		int n = flag ? s1.size() : s2.size();

		for(int i=0;i<n;i++)
		{
			node<int>* temp = flag ? s1.top() : s2.top();
			flag ? s1.pop() : s2.pop();
			cout<<temp->data<<' ';

			if(flag)
			{
				if(temp->left)
					s2.push(temp->left);
				if(temp->right)
					s2.push(temp->right);
			}
			else
			{
				if(temp->right)
					s1.push(temp->right);
				if(temp->left)
					s1.push(temp->left);
			}
		}
	}
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	cout<<"\nSpiral level order: ";
	spiralOut(root);

	return 0;
}