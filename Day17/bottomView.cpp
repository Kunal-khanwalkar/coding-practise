#include<iostream>
#include<map>
#include<utility>
#include"tree.h"

void fillHdMap(node<int>* ptr, map<node<int>*,int> &hdmap)
{
	if(!ptr)
		return;
	fillHdMap(ptr->left,hdmap);
	hdmap[ptr] = INT_MAX;
	fillHdMap(ptr->right,hdmap);
}

void BottomView(node<int>* root)
{
	if(root==nullptr)
		return;

	int hd=0;
	map<node<int>*,int> hdmap;
	map<int,int> mp;
	queue<node<int>*> q;
	
	fillHdMap(root,hdmap);
	hdmap[root] = hd;	

	q.push(root);

	
	while(!q.empty())
	{
		node<int>* temp = q.front();
		q.pop();

		hd = hdmap[temp];
		mp[hd] = temp->data;

		if(temp->left)
		{
			hdmap[temp->left] = hd-1;
			q.push(temp->left);
		}
		if(temp->right)
		{
			hdmap[temp->right] = hd+1;
			q.push(temp->right);
		}
	}

	for(auto itr=mp.begin();itr!=mp.end();itr++)
		cout<<itr->second<<' ';	
}

int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder Traversal: ";
	t.inorder(root);

	cout<<"\nBottom view: ";
	BottomView(root);

	return 0;
}