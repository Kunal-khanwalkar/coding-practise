#include<iostream>
#include<queue>
using namespace std;


struct node {
	char data;
	node* left;
	node* right;
};



node* generate(int n)
{
	node* root = new node();
	root->data = 'E';
	root->left = nullptr;
	root->right = nullptr;

	while((n-1)>0)
	{

		n--;
	}

	return root;
}


char findProf(int level, int pos)
{
	if(level == 1)
		return 'E';

	if(findProf(level-1, (pos+1)/2) =='D' )
		return (pos%2) ? 'D' : 'E';

	return (pos%2) ? 'E' : 'D';
}


int main()
{
	int n = 4;

	//node* root = generate(n);

	int pos = 2;

	if(findProf(n,pos) == 'E')
		cout<<"Engineer";
	else
		cout<<"Doctor";

	return 0;
}