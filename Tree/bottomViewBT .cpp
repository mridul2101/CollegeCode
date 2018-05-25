//Left View of Binary Tree

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void insertBST(struct node**, int);
void insertBT(struct node**, int);

void display(struct node*);
void leftView(struct node*);
void leftViewWithoutLevel(node*);


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
	//leftView(ptr);
	leftView(ptr);
	cout<<endl;
	return 1;
}



void leftView(node *root)
{
	if(root == NULL)
		return;
	queue<node*> que;
	stack<node*>stk;
	que.push(root);
	int level = 0;
		
	while(!que.empty())
	{
		node *ptr;
		ptr = que.front();
		que.pop();
		stk.push(ptr);
		//cout<<ptr->value<<"  ";
		
		if(ptr->right != NULL)
			que.push(ptr->right);
		if(ptr->left != NULL)	
			que.push(ptr->left);
	}
	while(!stk.empty())
	{
		node *ptr=stk.top();stk.pop();
		cout<<ptr->value<<" ";
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




