//Convert BST to Doubly Linked List

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void insertBST(struct node**, int);
void insertBT(struct node**, int);

void display(struct node*);
void displayList(struct node*);
void treetolist(struct node*, struct node**, struct node**);

struct node
{
	int value;
	node *left,*right;
	int level;
};

int main()
{
	struct node *root;
	root = NULL;
	int n;
	cin>>n;
	struct node *ptr;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insertBST(&root, val);
		
	}
	
	ptr = root;

	struct node *prev, *listhead;
	prev = listhead = NULL;
	treetolist(ptr, &prev, &listhead);
	
	displayList(listhead);
	cout<<endl;
	return 1;
}

void displayList(struct node *listhead)
{
	struct node *ptr;
	ptr = listhead;
	while(ptr != NULL)
	{
		cout<<ptr->value<<"  ";
		ptr = ptr->right;
	}
	return;
}


void treetolist(struct node *ptr , struct node **prev, struct node **listhead)
{
	if(ptr == NULL)
		return;
	treetolist(ptr->left, prev, listhead);

	if(*listhead == NULL)
	{
		
		*listhead = ptr;
		(*listhead)->left = NULL;
	}
	if(*prev != NULL)
	{
		struct node *temp;
		temp = ptr;
		temp->left = *prev;
		(*prev)->right = temp;
	}
	*prev = ptr;
	
	treetolist(ptr->right, prev, listhead);
	return;
}

void display(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		display((ptr->left));
		cout<<ptr->value<<"  ";
		display(ptr->right);
	}
}

void insertBT(struct node **root, int value)
{
	struct node *temp;
	temp = new node();
	temp->value = value;
	temp->left = temp->right = NULL;
	temp->level = -1;
	if(*root == NULL)
	{
		temp->level = 1;
		*root = temp;
		return;
	}
	queue<node*> stk;
	node *ptr;
	ptr = *root;
	stk.push(ptr);
	node *prev = NULL;
	int flag = -1;
	while(!stk.empty())
	{
		node* ptr;
		ptr = stk.front();
		stk.pop();
		
		if(ptr->left == NULL)
		{
			prev = ptr;
			flag = 0;
			//stk.clear();		
			break;
		}
		if(ptr->right == NULL)
		{
			prev = ptr;
			flag = 1;
			//stk.clear();		
			break;
		}
		stk.push(ptr->left);
		stk.push(ptr->right);
		
	}
	temp->level = prev->level + 1;

	if(flag == 0)
		prev->left = temp;
	else
		prev->right = temp;

	while(!stk.empty()) stk.pop();
		
	return;	
}

void insertBST(struct node **root, int value)
{
	struct node *temp;
	temp = new node();
	temp->value = value;
	temp->left = temp->right = NULL;
	temp->level = -1;
	
	if(*root == NULL)
	{	
		temp->level = 1;	
		*root = temp;
		
		return;
	}

	struct node *ptr, *prev;
	ptr = *root;
	prev = NULL;

	while(ptr != NULL)
	{
		prev = ptr;
		if(ptr->value > value)
			ptr = ptr->left;
		else 
			ptr = ptr->right;
	}

	temp->level = prev->level + 1;	
	
	if(prev->value > value)
		prev->left = temp;
	else
		prev->right = temp;
			
	return;
}




