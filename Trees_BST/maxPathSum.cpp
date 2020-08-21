#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}




void maxPathSumUtil(node* root, int &res)
{
	if(!root)
		return;
	
}




int maxPathSum(node* root)
{
	int res = INT_MIN;
	maxPathSumUtil(root,res);
	return res;
}



int main()
{

	struct Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 
    cout << "Max pathSum of the given binary tree is "<< maxPathSum(root); 


	return 0;
}