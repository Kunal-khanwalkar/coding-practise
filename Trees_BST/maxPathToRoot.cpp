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


bool printPath(node* root, node* target_leaf)
{
	if(!root)
		return false;

	if(root == target_leaf || printPath(root->left,target_leaf) || printPath(root->right,target_leaf))
	{
		cout<<root->data<<' ';
		return true;
	}
	return false;
}


void getTargetLeaf(node* root, int &max_sum, int curr_sum, node** target_leaf)
{
	if(!root)
		return;

	curr_sum += root->data;

	if(!root->left && !root->right)
		if(curr_sum > max_sum)
		{
			max_sum = curr_sum;
			*target_leaf = root;
		}

	getTargetLeaf(root->left,max_sum,curr_sum,target_leaf);
	getTargetLeaf(root->right,max_sum,curr_sum,target_leaf);
}


int maxSumPath(node* root)
{
	if(!root)
		return 0;

	node* target_leaf;
	int max_sum = INT_MIN;

	getTargetLeaf(root, max_sum,0,&target_leaf);
	printPath(root,target_leaf);

	return max_sum;
}



int main()
{
	node* root = nullptr;
	
	root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(7); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 

    cout << "Following are the nodes on the maximum sum path \n"; 
    int sum = maxSumPath(root); 
    cout << "\nSum of the nodes is " << sum; 

	return 0;
}