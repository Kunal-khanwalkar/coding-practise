#include"tree.h"
using namespace std;


void invert(node<int>* root)
{
	if(root == nullptr)
		return;

	node<int>* temp;
	invert(root->left);
	invert(root->right);

	temp = root->left;
	root->left = root->right;
	root->right = temp;
}


void iter_invert(node<int>* root)
{
	if(root==nullptr)
		return;

	queue<node<int>*> q;
	q.push(root);

	while(!q.empty())
	{
		node<int>* curr = q.front();
		q.pop();

		swap(curr->left, curr->right);

		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
}


int main()
{
	tree<int> t;
	node<int>* root = t.returnroot();
	root = t.create();

	cout<<"\nInorder traversal: ";
	t.inorder(root);

	iter_invert(root);

	cout<<"\nInorder traversal: ";
	t.inorder(root);	
	return 0;
}