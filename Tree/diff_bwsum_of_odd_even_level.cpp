//Difference between sums of odd level and even level nodes of a Binary Tree

#include<iostream>
using namespace std;

void insert(struct node**, int);
void display(struct node*);
void EvenOddLevel(struct node*, int*, int*);

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
	display(ptr);
	cout<<endl;

	int diff, even, odd;
	even = odd = 0;
	ptr = root;
	EvenOddLevel(ptr, &even, &odd);
	diff = even - odd;
	cout<<even<<" - " <<odd<<" = "<<diff<<endl;
	return 1;
}

void EvenOddLevel(struct node *ptr, int *even, int *odd)
{
	if(ptr == NULL)
		return;
	else
	{
		EvenOddLevel(ptr->left, even, odd);
		if((ptr->level % 2) == 0)
			*even += ptr->value;
		else
			*odd += ptr->value;
		EvenOddLevel(ptr->right, even, odd);
	}

	
}

void display(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		display((ptr->left));
		cout<<ptr->value<<"  "<<ptr->level<<endl;
		display(ptr->right);
	}
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










