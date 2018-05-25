//Create new mirror tree of a given Binary Tree

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void insertBST(struct node**, int);
void insertBT(struct node**, int);

void display(struct node*);
void mirrorCreate(struct node*, struct node*, struct node**, char);

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
		insertBT(&root, val);
		
	}
	
	struct node *root1, *node2;
	root1 = node2 = NULL;
	ptr = root;
	cout<<"Original Tree : ";	
	display(ptr);ptr = root;cout<<endl;
	mirrorCreate(ptr, node2, &root1,'r');
	
	cout<<"Mirrored Tree : ";
	ptr = root1;
	display(ptr);

	cout<<endl;
	return 1;
}


void mirrorCreate(struct node *node1, struct node *node2, struct node **root1, char child)
{
	if(node1 == NULL)
		return;
	else
	{
		struct node *n;
		n = new node();
		n->value = node1->value;
		n->left = n->right = NULL;
		if(node2 == NULL)
		{
			node2 = *root1 = n;
		}
		else
		{		
			if(child == 'l')
			{
				(node2)->right = n;
			}
			if(child == 'r')
			{
				(node2)->left = n;
			}
			node2 = n;
		}
		mirrorCreate(node1->left, node2, root1, 'l');
		mirrorCreate(node1->right, node2, root1, 'r');	
	}
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




