#include<iostream>
#include<map>
#include<utility>
#include"tree.h"


void fillMap(node<int>* root, int d, int l, map<int,pair<int,int>> &mp)
{
	if(root==nullptr)
		return;

	if(mp.count(d)==0)
		mp[d] = {root->data,l};
	else if(mp[d].second > l)
		mp[d] = {root->data,l};

	fillMap(root->left,d-1,l+1,mp);
	fillMap(root->right,d+1,l+1,mp);
}



void topView(node<int>* root)
{
	map<int,pair<int,int>> mp;
	fillMap(root,0,0,mp);

	for(auto itr=mp.begin();itr!=mp.end();itr++)
		cout<<itr->second.first<<' ';
}



void fillHdMap(node<int>* ptr, map<node<int>*,int> &hdmap)
{
	if(!ptr)
		return;
	fillHdMap(ptr->left,hdmap);
	hdmap[ptr] = INT_MAX;
	fillHdMap(ptr->right,hdmap);
}


void topViewMap(node<int>* root)
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

		hd = hdmap[root];
		if(mp.count(hd)==0)
			mp[hd] = root->data;

		if(root->left)
		{
			hdmap[root->left] = hd-1;
			q.push(root->left);
		}
		if(root->right)
		{
			hdmap[root->right] = hd+1;
			q.push(root->right);
		}
		q.pop();
		root = q.front();
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

	cout<<"\nTop view: ";
	topViewMap(root);

	return 0;
}