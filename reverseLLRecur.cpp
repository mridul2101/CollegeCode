//Reverse Linked List Recursively

#include<iostream>
using namespace std;

void display(struct node*);
void insert(struct node**, int);
node* reverseLLRecur(struct node*, struct node**);

struct node 
{
	int value;
	struct node *next;
};

int main()
{
	int n;
	cin>>n;
	struct node *root;
	root = NULL;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		insert(&root,p);
	}
	display(root);

	node *ptr;
	ptr = root;
	reverseLLRecur(ptr, &root);
	display(root);

}

node* reverseLLRecur(struct node *ptr, struct node **root)
{
	if(ptr == NULL)
		return NULL;
	else
	{
		node *temp;
		temp = reverseLLRecur(ptr->next, &*root);
		if(temp == NULL)
		{
			*root = ptr;
			ptr->next = NULL;
		}
		else
		{
			temp->next = ptr;
			ptr->next = NULL;	
		}
	}
	return ptr;
	
}


void display(struct node *root)
{
	node* ptr;
	ptr = root;
	while(ptr!=NULL)
	{
		cout<<ptr->value<<"  ";
		ptr = ptr->next;
	}
	cout<<endl;
	return;
}
	
void insert(struct node **root, int p)
{
	struct node *temp;
	temp = new node();
	temp->value = p;
	temp->next = NULL;
	if(*root == NULL)
	{
		*root = temp;		
		return;
	}
	node* ptr;
	ptr = *root;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
	return;
}








