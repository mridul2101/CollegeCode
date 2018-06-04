#include<iostream>
using namespace std;
#include<stdlib.h>

struct node
{
	struct node *left,*right;
	int data;
	int left_ht,right_ht,depth;
};
struct node *root;
int Dia_tree(struct node*);

void insert(int);
int maxm=0;

int main()
{
	int n;
	cin>>n;
	root=NULL;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		insert(a[i]);
	}
	struct node *ptr;
	ptr=root;
	Dia_tree(ptr);
	cout<<maxm<<endl;

}

int Dia_tree(struct node *ptr)
{int count=0;
	if(ptr!=NULL)
	{
		ptr->left_ht=Dia_tree(ptr->left);
		ptr->right_ht=Dia_tree(ptr->right);
		if(ptr->left_ht >= ptr->right_ht)
			count=ptr->left_ht;
		else
			count=ptr->right_ht;					
		if((ptr->left_ht+ptr->right_ht)>maxm)
			maxm=(ptr->left_ht+ptr->right_ht);
		return (count+1);
	}
	else
		return 0;
}



void insert(int value)
{
	struct node *n;
	n=new node();
	n->data=value;
	n->right=n->left=NULL;
	n->left_ht=n->right_ht=n->depth=0;
	if(root==NULL)
	{
		root=n;
		return;
	}
	struct node *ptr,*parent;
	ptr=root;
	parent=NULL;
	while(ptr!=NULL)
	{
		parent=ptr;
		if(value<=ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	if(value<parent->data)
		parent->left=n;
	else
		parent->right=n;
	return;
}			








