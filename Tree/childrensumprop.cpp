//Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only increment data values in any node (You cannot change structure of tree and cannot decrement value of any node)


#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void insertBST(struct node**, int);
void insertBT(struct node**, int);

void display(struct node*);
int childsumprop(struct node*);

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
	display(ptr);
	ptr = root;cout<<endl;
	childsumprop(ptr);
	ptr = root;
	display(ptr);

	cout<<endl;
	return 1;
}


int childsumprop(struct node *ptr)
{
	int l = 0, d = 0;
	if(ptr == NULL) 
		return 0;
	else
	{	
		
		if(ptr->left != NULL)
			l = childsumprop(ptr->left);
		
		if(ptr->right != NULL)
			d = childsumprop(ptr->right);	
		
		if((l+d) >= ptr->value)
			ptr->value = (l+d);
		else
		{
			struct node *temp;
			temp = ptr->left;
			int diff = ((ptr->value)-(l+d));
			cout<<diff<<endl;
			while(temp != NULL)
			{	
				temp->value += diff;
				temp = temp->left;
			}
		}
	}
	return (ptr->value);
				
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




