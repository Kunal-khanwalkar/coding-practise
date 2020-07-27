#include<iostream>
#include"tree.h"
using namespace std;


int search(int *arr, int start, int end, int val)
{
	for(int i=start; i<=end; i++)
		if(arr[i] == val)
			return i;
	return 0;
}

node<int>* buildTree(int *in, int *pre, int start, int end)
{
	static int preIndex = 0;

	if(start > end)
		return nullptr;

	node<int>* temp = new node<int>;
	temp->data = pre[preIndex++];
	temp->left = nullptr;
	temp->right = nullptr;

	if(start == end)
		return temp;

	int inIndex = search(in,start,end,temp->data);

	temp->left = buildTree(in,pre,start,end-1);
	temp->right = buildTree(in,pre,start+1,end);

	return temp;
}



int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	//root = t.create();

	int in[] = {4,2,5,1,6,3};
	int pre[] = {1,2,4,5,3,6};
	int len = sizeof(pre)/sizeof(int);

	root = buildTree(in,pre,0,len-1);


	cout<<"\nInorder traversal: ";
	t.inorder(root);

	return 0;
}