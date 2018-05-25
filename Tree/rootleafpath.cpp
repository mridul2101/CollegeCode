//Root to Leaf Path one per line in given Binary Tree

#include<iostream>
#include<stack>
#include<queue>
#include<list>
using namespace std;

void insertBST(struct node**, int);
void insertBT(struct node**, int);

void display(struct node*);
void rootleafpath(struct node*, list<int>);

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
	
	ptr = root;
	list<int> mylist;
	rootleafpath(ptr, mylist);	

	
	cout<<endl;
	return 1;
}


void rootleafpath(struct node* node, list<int> mylist)
{
	if(node->left == NULL && node->right == NULL)
	{
		list<int>::iterator it;
		it = mylist.begin();
		mylist.push_back(node->value);
		for(;it != mylist.end() ; it++)
		{
			cout<<*it<<"  ";
		}
		cout<<endl;
	}
	else
	{
		mylist.push_back(node->value);
		if(node->left != NULL)
			rootleafpath(node->left, mylist);
		if(node->right != NULL)
			rootleafpath(node->right, mylist);
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




