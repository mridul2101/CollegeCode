//Reverse Level Order Traversal

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void insert(struct node**, int);
void reverseLevelOrder(node*);

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
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(&root, val);
	}
	struct node *ptr;
	ptr = root;
	reverseLevelOrder(ptr);
	
	return 1;
}


void reverseLevelOrder(node *root)
{
	node *ptr;
	ptr = root;

	stack<node*>mystk;
	queue<node*>myqueue;

	myqueue.push(ptr);
	while(!myqueue.empty())
	{
		node *temp = myqueue.front();
		myqueue.pop();
		mystk.push(temp);
		if(temp->left != NULL)
			myqueue.push(temp->left);
		if(temp->right != NULL)
			myqueue.push(temp->right);

	}
	while(!mystk.empty())
	{
		node *temp;
		temp = mystk.top();
		mystk.pop();
		cout<<temp->value<<"  ";
	}
	cout<<endl;
	return;

}

void insert(struct node **root, int value)
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


