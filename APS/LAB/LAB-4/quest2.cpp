#include<iostream>
using namespace std;
#include<stdlib.h>

struct node
{
	struct node *left,*right;
	int data;
};
struct node *root;
void insert(int);
void postorder(struct node*,int*);
int p=0;
int main()
{
	int n;
	cin>>n;
	root=NULL;
	int a[n],post[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		insert(a[i]);
	}
	
	postorder(root,post);
	int t,k;
	cin>>t;
	while(t--)
	{
		cin>>k;
		cout<<post[k-1]<<endl;
	}
}

void postorder(struct node *root,int post[])
{
	struct node *ptr=root;
	if(ptr==NULL)
		return;
	postorder(ptr->left,post);
	postorder(ptr->right,post);
	post[p]=ptr->data;
	p++;
}

void insert(int value)
{
	struct node *n;
	n=new node();
	n->data=value;
	n->right=n->left=NULL;
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








