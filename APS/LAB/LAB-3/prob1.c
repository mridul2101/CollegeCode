/* A user is typing a sentence using his keyboard. He uses only the keys, 'a' - 'z', H (home) and E(end). Given the sequence of key presses, find the line that is printed on the screen finally. Initially, a cursor is placed at the beginning of empty line and the following actions are performed with each key stroke.

- when 'a'-'z' is pressed, its printed at current cursor position after moving the rest of the string to right. For eg. If the current cursor position is at t in the string "deter", pressing a 'x' key results in the string "dexter".

- when 'H' is pressed, cursor moves to the beginning. For eg: pressing 'H' when we have "apple" results in string "apple"

- when 'E' is pressed, cursor moves to the end of the string. For eg: pressing 'E' when we have "apple" results in string "apple "

Its just like any normal editors we use. Try it out pressing 'a' - 'z', Home and End keys to get a feel of it :)
Use only C to code this problem. For other problems you can use C/C++

Input:
Only one line, contains a long string of at most 100000 valid characters

Output:
Print the final string in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:
Time Limit : 1s 

Sample Case 2:

Input:
rHsEocHpEkHaEs

Output:
apsrocks\n
*/

#include<stdio.h>
#include<stdlib.h>

void insert(char);
void display();

struct node
{
	char ch;
	struct node* next;
};
struct node *first=NULL,*cur_loc=NULL,*last=NULL;

int main()
{
	char str[100001];
	int i;
	first=NULL;
	cur_loc=NULL;
	last=NULL;
	scanf(" %s",str);

	for(i=0;str[i]!='\0';i++)
	{
		insert(str[i]);
	}
	display();
	return(0);
}
void insert(char c)
{
	if(c!='H' && c!='E')
	{
		struct node *n;
		n=(struct node*)malloc(sizeof(struct node));
		n->ch=c;
		if(first==NULL)
		{
			n->next=NULL;
			first=n;
			cur_loc=n;
			last=n;
			return;
		}
		
		if(cur_loc==NULL)
		{
			n->next=first;
			first=n;
			cur_loc=n;
			return;
		}
		if(cur_loc->next==NULL)
		{	n->next=NULL;
			cur_loc->next=n;
			cur_loc=n;
			last=n;
		}	
		else
		{
			n->next=cur_loc->next;
			cur_loc->next=n;
			cur_loc=n;
		}
		return;
	}
	else if(c=='H')
		 {
			 cur_loc=NULL;
		 }
		 else if(c=='E')
			  {				 
  			   if(first==NULL)
				{cur_loc=NULL;return;}		
			cur_loc=last;
			}
			
		return;
}

void display()
{
	struct node *ptr;
	ptr=first;
	while(ptr!=NULL)
	{
		printf("%c",ptr->ch);
		ptr=ptr->next;
	}
	
	printf("\n");
	return;
}



