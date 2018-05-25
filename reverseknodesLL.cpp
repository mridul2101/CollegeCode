//REVERSE Linked List by k nodes and Complete
//INPUT 1 2 3 4 5 6 7   ; k = 3
//OUTPUT 3 2 1 7 6 5

#include<iostream>
using namespace std;

void insert(struct node**, int);
void display(struct node**);
void reverse_k(struct node**, int);
node* reverse_k2(struct node*, int);
void reverseLL(struct node**);


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


	cout<<"ORIGINAL LL"<<endl;
	display(&list1);
	cout<<endl;

	reverseLL(&list1);
	cout<<"AFTER Reverse LL (cmplete)"<<endl;
	display(&list1);
	cout<<endl;
	reverseLL(&list1);

	cin>>k;

	list1 = reverse_k2(list1, k);
	cout<<"AFTER Reverse By k"<<endl;
//	display(&list1);
        while(list1 != NULL){
            cout<<list1->value<<" ";
            list1 = list1->next;
        }
	cout<<endl;
	return 1;
}

void reverseLL(struct node **start)
{
	struct node *temp, *prev, *next;
	temp = *start;
	prev = next = NULL;

	while(temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*start = prev;
	return;	

}

node* reverse_k2(struct node *start, int k){
	struct node *curr, *prev, *next;
	curr = start;
	int count = k;
	while(curr != NULL && count>0){
                cout<<curr->value<<"  ";
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count--;
	}

	if(next != NULL){
		start->next = reverse_k2(next, k);
	}
        cout<<"Hello "<<prev->value<<endl;
	return prev;
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




