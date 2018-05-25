/*
 Given two numbers represented by two linked lists, write a function that returns sum list. The sum list is linked list representation of addition of two input numbers.
Example

Input:
 First List: 5->6->3  // represents number 563
 Second List: 8->4->2 //  represents number 842
Output
 Resultant list: 1->4->0->5  // represents number 1405
*/
#include<iostream>
#include<stack>
using namespace std;

void insert(struct node**, int);
void display(struct node**);
struct node* addition(struct node**, struct node**);

struct node
{
	int value;
	struct node *next;
};

int main()
{
	struct node *list1,*list2, *list;
	list1 = list2 = list = NULL;
	
	int f1,f2;
	cin>>f1>>f2;
	
	while(f1 != 0)
	{
		insert(&list1, f1 % 10);
		f1 /= 10;
	}
	
	while(f2 != 0)
	{
		insert(&list2, f2 % 10);
		f2 /= 10;
	}

	cout<<"BEFORE MERGING"<<endl;
	display(&list1);
	display(&list2);
	cout<<endl;

	cout<<"AFTER ADDITION"<<endl;
	list = addition(&list1, &list2);	
	display(&list);

	cout<<endl;
	return 1;
}

struct node* addition(struct node **list1, struct node **list2)
{
	struct node *list;
	stack<int> s1;
	stack<int> s2;
	
	struct node *temp;
	temp = *list1;
	while(temp != NULL)
	{
		s1.push(temp->value);
		temp = temp->next;
	}
	temp = *list2;
	while(temp != NULL)
	{
		s2.push(temp->value);
		temp = temp->next;
	}

	int carry = 0, value = -1;
	int p1,p2,v;

	while((!s1.empty()) && (!s2.empty()))
	{
		p1 = s1.top();
		s1.pop();
		p2 = s2.top();
		s2.pop();
		v = p1 + p2 +carry;
		carry = v / 10;
		value = v % 10;
		
		insert(&list, value);

	}
				
	while(!s1.empty())
	{	
		p1 = s1.top();
		s1.pop();
		v = p1 + carry;
		carry = v / 10;
		value = v % 10;
		insert(&list, value);
	}
	while(!s2.empty())
	{
		p1 = s2.top();
		s2.pop();
		v = p1 + carry;
		carry = v / 10;
		value = v % 10;
		insert(&list, value);
	}
	if(carry != 0)
		insert(&list, carry);
	
	return list;
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
	temp->next = *list;
	*list = temp;
	return;
}




