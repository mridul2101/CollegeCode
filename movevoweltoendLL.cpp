//Move Vowel to End

#include<iostream>
using namespace std;

void display(struct node*);
void insert(struct node**, char);
node* reverseLLRecur(struct node*, struct node**);
node* moveVowel(node**);

struct node 
{
	char value;
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
		char p;
		cin>>p;
		insert(&root,p);
	}
	display(root);

	node *ptr;
	ptr = root;
	root = moveVowel(&ptr);
	ptr = root;
	display(root);

}

node* moveVowel(node **root)
{
	node *ptr, *prev, *end;
	ptr = *root;
	if(ptr == NULL || ptr->next ==NULL)
		return *root;

	int count=0,flag = 0;
	end = ptr;
	prev = NULL;
	while(end->next != NULL)
	{
		count++;
		end = end->next;
	}
	
	node *pp;
	pp = NULL;count++;
	for(int i=0;i<count;i++)
	{
		prev = ptr;
		if(ptr->value == 'a' || ptr->value == 'e' || ptr->value == 'i' || ptr->value == 'o' ||ptr->value == 'u')
		{
			
			prev = ptr->next;
			end->next = ptr;
			ptr->next = NULL;
			if(flag == 0 && prev != NULL)
			{
				*root = prev;
			}
			else {
				pp->next = prev;
				}
			end = end->next;
			ptr = prev;
			
		}
		else
		{
			pp = prev;
			flag = 1;
			ptr = ptr->next;
		}
		display (*root);
		cout<<endl;
	}	

	return *root;		 	

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
	
void insert(struct node **root, char p)
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








