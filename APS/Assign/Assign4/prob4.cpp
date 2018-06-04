#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#include<stdlib.h>

struct node
{
	struct node *left,*right;
	int data;
};
struct node *root,*com;
stack<node*>common;
stack<node*>common1;
queue<node*>common3;
stack<int>c1;

void insert(int);
void inorder(struct node*);
void postorder(struct node*);
void levelorder(struct node*);

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
	
	com=root;
	inorder(com);
	cout<<endl;

	com=root;	
	postorder(com);
	cout<<endl;

	com=root;
	levelorder(com);
	cout<<endl;

}
void inorder(struct node *ptr)
{
	do
	{
		while(ptr!=NULL)
		{
		   common.push(ptr);
		   ptr=ptr->left;
		}
		ptr=common.top();
		common.pop();		
 		cout<<ptr->data<<" ";
		ptr=ptr->right;		
	}while(ptr!=NULL or !common.empty());
}


void postorder(struct node *ptr)
{
	int value=ptr->data;
	do
	{
		while(ptr!=NULL)
		{
		   common1.push(ptr);
		   //c1.push(ptr->data);
		   if(ptr->right!=NULL)
		   {
			ptr->right->data=-(ptr->right->data);
			common1.push(ptr->right);
			//c1.push(-(ptr->right->data));
		   }
		   ptr=ptr->left;
		}
		ptr=common1.top();
		//value=c1.top();
		common1.pop();
		//c1.pop();
		while(ptr->data>=0)
		{
			cout<<ptr->data<<" ";
			if (ptr->data==value)
			   break;
			ptr=common1.top();
			common1.pop();
		}
		if (ptr->data==value)
			   break;
			
		if(ptr->data<0)
		{
			ptr->data=-(ptr->data);
		}
	}while(ptr!=NULL or !common1.empty());

}

void levelorder(struct node *ptr)
{
		while(ptr!=NULL or !common3.empty())
		{
			cout<<ptr->data<<" ";
			if(ptr->left!=NULL)
			   common3.push(ptr->left);
			
			if(ptr->right!=NULL)
			   common3.push(ptr->right);
			
		if(common3.size()==0)
		  break;
		ptr=common3.front();
		common3.pop();		
		}
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








