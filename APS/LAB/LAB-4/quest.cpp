#include<iostream>
#include<stack>
using namespace std;

long long int monkey_funct(int *a,int,long long int);
stack<long long int>stack_n;
int main()
{
	int n;long long int count=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//stack_n.push(999999);
	
	count=monkey_funct(a,n,count);
	cout<<count<<endl;
return(0);
}
	
long long int monkey_funct(int a[],int n,long long int count)
{
  int flag=0,size=0,max=0;
  stack_n.push(100000000000000);
   for(int i=1;i<=n;i++)
   {  int num;	
	while(stack_n.top()<a[i])
	{
		int top;
		top=stack_n.top();					
		flag=2;
		num=10;
		for(int k=0;k<=num;k++)
		{
		  max=max+(k*2);
		 }
		max=top;
		flag=0;
		while(stack_n.top()==max and !stack_n.empty())
		{
		  flag++;
		  // top=stack_n.top();
		  count=count+(n-i);
		  stack_n.pop();
		 //if(!stack_n.empty())
		  //top=stack_n.top();
		}
		size=stack_n.size();			
		if(size>=2)
		count=count+flag*(size-2);
	}
	stack_n.push(a[i]);
    }
size=stack_n.size();
//cout<<count<<" "<<size<<" ";

for(int i=1;size>2;i++) 
{  
    //while(i<size)
    //{
	int top;
	top=stack_n.top();
	max=top;
	flag=0;
	while(top==max and !stack_n.empty())
	{
	   stack_n.pop();
	   flag++;
	   top=stack_n.top();
	}
	size=stack_n.size();
	if(size>1)
	count+=flag*(size-2);
//	i++;
    //}
}
return(count);
}










