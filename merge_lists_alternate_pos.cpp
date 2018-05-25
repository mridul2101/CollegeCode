//Merging of Two Lists at Alternate positions in First list

#include<iostream>
using namespace std;

void insert(struct node**, int);
void display(struct node**);
void merge(struct node**, struct node**);

struct node
{
	int value;
	struct node *next;
};

int main()
{
	struct node *list1,*list2;
	list1 = list2 = NULL;

	int n1,n2;
	cin>>n1>>n2;
	for(int i=0 ;i<n1;i++)
	{
		int value;
		cin >> value;
		insert(&list1, value);
	}
	
	for(int i=0 ;i<n2;i++)
	{
		int value;
		cin >> value;
		insert(&list2, value);
	}
	cout<<"BEFORE MERGING"<<endl;
	display(&list1);
	display(&list2);
	cout<<endl;

	merge(&list1, &list2);
	cout<<"AFTER MERGING"<<endl;
	display(&list1);
	display(&list2);
	cout<<endl;
	return 1;
}

void merge(struct node **list1, struct node **list2)
{
	struct node *ptr1, *ptr2, *temp;
	ptr1 = *list1;
	ptr2 = *list2;
	temp = NULL;

	while(ptr1 != NULL && ptr2 != NULL)
	{		
		temp = ptr2->next;
		ptr2->next = ptr1->next;
		ptr1->next = ptr2;
		ptr2 = temp;
		ptr1 = ptr1->next->next;
	}
	*list2 = ptr2;
	return;
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




