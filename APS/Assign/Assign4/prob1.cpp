#include<iostream>
#include<stack>
using namespace std;
#include<stdlib.h>

struct node
{
	struct node *left,*right;
	int data;
	int info;
};
struct node *root;
struct node *ptr=NULL;
void inorder(struct node*);
stack<node*>common;
void find_max(struct node*,struct node*);
void insert(int,int);
int size(int);
int flag=0;
int r,s,maxm=0;

int main()
{
	int n,max_len=0;
	cin>>n;
	root=NULL;
	int a[n];

	for(int i=0;i<n;i++)
	{
		int c=0,p;
		cin>>a[i];
		p=a[i];
		while(p!=0)
		{
			p=p>>1;
			c++;
		}
		if(max_len<c)
		{max_len=c;}		
	}
		insert(-1,-1);
	//cout<<max_len<<endl;
	for(int i=0;i<n;i++)
	{	ptr=root;
		flag=0;
		int s,max=max_len;
		s=size(a[i]);
		while(s!=max)
		{   
		    if(ptr->right==NULL)
		    {
			if(max==0)
			  flag=1;		  
		    	insert(0,a[i]);
		     }
		     else
		     {ptr=ptr->right;}
		    max--;
		}
		s--;
		while(s>=0)
		{
		  if(s==0)
			flag=1;
		   int p;
		   p=a[i];
		   p=((p>>s)&1);//cout<<s<<" "<<p<<endl;
		   if(p==1)
		   {
			   if(ptr->left==NULL)
			   {
				insert(1,a[i]);
			   }
			    else
			    {ptr=ptr->left;}
		   }
		   else
		   {
			if(ptr->right==NULL)
			   {insert(0,a[i]);}
			    else
			    {ptr=ptr->right;}
		   }
		   s--;		
		}
	}
	//inorder(root);
	struct node *ptr,*p;
	ptr=root;p=root;
	//if(ptr->left==NULL and ptr->right!=NULL)
	//{
	//	find_max(ptr
	find_max(ptr->left,p->right);
	cout<<maxm<<endl;
}

void find_max(struct node *ptr,struct node *p)
{
	struct node *pr=NULL;
	while(ptr!=NULL and p!=NULL)
	{ //cout<<ptr->data<<"   "<<p->data<<endl;
	   if((ptr->info != -1) or (p->info != -1))
		{break;}
	   if((ptr->left==NULL and ptr->right==NULL) or (p->left==NULL and p->right==NULL))
		break;

	   if(ptr->left!=NULL and ptr->right!=NULL)
	   {//cout<<"fvfdvz";
		struct node *a1,*a2;
		a1=ptr->left;a2=p->right;
		find_max(a1,a2);
		a1=ptr->right;a2=p->left;
		find_max(a1,a2);
		return;			
	   }
	  else if(ptr->left!=NULL)
	    {
		
//		cout<<prev->data<<endl;
		ptr=ptr->left;
	 	if(p->right!=NULL)
		{
		   pr=p;
		    p=p->right;
		}
		else
		{
		pr=p;
		    p=p->left;
		}
	     }
	    else
	    {
		
//		cout<<prev->data<<endl;
		ptr=ptr->right;
		if(p->left!=NULL)
		{
			pr=p;
			p=p->left;
		}
		else
		{	pr=p;
			p=p->right;
		}
	    }
	}
	
	r=ptr->info;
	if(p!=NULL)
	s=p->info;
	else
	{if(pr!=NULL)
		s=pr->info;
	}
	if(s==-1)
	  s=0;
//cout<<r<<" "<<s<<endl;
	if(maxm < (r^s))
	  maxm=r xor s;
//	cout<<maxm<<endl;
}




void insert(int value,int val1)
{
	struct node *n;
	n=new node();
	n->data=value;
	n->right=n->left=NULL;
	if(flag==1)
	   n->info=val1;
	else
	   n->info=-1;
	if(root==NULL)
	{
		root=n;
		return;
	}
	//struct node *ptr,*parent;
//	ptr=root;
	if(value==1)
		{ptr->left=n;ptr=ptr->left;}
	else
		{ptr->right=n;ptr=ptr->right;}
	return;
}			



int size(int a)
{
	int c=0,p;
	p=a;
	while(p!=0)
	{
		p=p>>1;
		c++;
	}
  return (c);
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
