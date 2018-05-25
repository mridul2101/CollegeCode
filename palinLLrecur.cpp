/*
Palindrom of Linked List Recursive
*/

#include<iostream>
using namespace std;

void insert(struct node**, int);
void display(struct node**);
void reverse_k(struct node**, int);
bool palinRR(struct node**, node*);
                                                                                                                                       
struct node
{
	int value;
	struct node *next;
};

int main()
{
	struct node *list1;
	list1 = NULL;

	int n1,k;
	cin>>n1;
	for(int i=0 ;i<n1;i++)
	{
		int value;
		cin >> value;
		insert(&list1, value);
	}
	//cout<<"Insert k = ";
	
	
	
	node *left,*right;
	left = right = list1;
	cout<<"IS PALINDROM : "<<palinRR(&left, right)<<endl<<endl;	

	cout<<endl;
	return 1;
}

bool palinRR(struct node **left, node *right)
{
	bool flag;
	if(right == NULL)
		return true;	
	
	flag = palinRR(left, right->next);
	if(flag == false) return false;
	if((*left)->value == (right)->value)
		flag = true;
	else
	{flag = false;}

	(*left) = (*left)->next;
	
	return flag;

}

void reverse_k(struct node **start, int k)
{
	struct node *tempstart,*temp;
	tempstart = *start;
	temp = *start;
	int flag = 0;
	struct node *start3node;
	start3node = *start;
	while(true)
	{
		for(int i=1;(i<(k)) && (temp !=NULL);i++)
		{//cout<<"HELLO "<<temp->value<<endl;
			temp = temp->next;
		
		}
		if(temp == NULL) break;
	
		struct node *newstart;
		newstart = temp->next;
		
		struct node *prev,*cur,*next;
		prev = next = NULL;
		cur = tempstart;	
		while(cur != newstart)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		
		if(flag == 0)
		{
			*start = prev;
			flag = 1;
		}
		else
		{
			start3node->next = prev;
		}
		start3node = tempstart;
		tempstart->next = cur;
		temp = tempstart = newstart;
		//tempstart = tempstart->next;
	}
	

}

void display(struct node **list)
{
	struct node *ptr;
	ptr = *list;
	while(ptr != NULL)
	{
		cout<<ptr->value<<"  ";
		ptr = ptr->next;
	}
	cout<<endl;
	return;
}

void insert(struct node **list, int value)
{
	struct node *temp;
	temp = new node();
	temp->value = value;
	temp->next = NULL;
	if(*list == NULL)
	{
		*list = temp;
		return;
	}
	struct node *ptr, *prev;
	ptr = *list;
	prev = NULL;
	while(ptr != NULL)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = temp;	
	return;
}




