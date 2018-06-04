#include<iostream>
using namespace std;

#include<math.h>
#include<stdlib.h>
#include<string.h>

void multiply(int p[],int x);
int check(char[]);

int main()
{       
	char *a;
        a=(char*)malloc(512*sizeof(char*));
	cin>>a;
	if(!check(a))
	   {cout<<"ERROR: INVALID TYPE INPUT\n";exit(1);}
	
	int n,size;
	n=atoi(a);
	delete(a);
	if(n<1 || n>1000)
		{cout<<"ERROR: INVALID RANGE INPUT\n";exit(1);}
	
	size=(int)n*log10(2) +1;

	int p[size+1];
	for(int i=0;i<size+1;i++)
		p[i]=0;
	p[0]=1;
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<size+1;j++)
		{
			p[j]*=2;  
		}
	  for(int j=0;j<size+1;j++)
	  {
		if(p[j]>=10)
		{p[j+1]+=p[j]/10;		
		  p[j]=p[j]%10;
		}
	}}
int sum=0;
for(int i=0;i<size+1;i++)
{sum+=p[i];}cout<<sum;
return(0);
}   


int check(char a[])
{int l,flag=0,i;
	l=strlen(a);
	for(i=0;i<l;i++)
	 {
		if(!isdigit(a[i]))
		{flag=1; break;}
	}
if(flag==1)
{return(0);}
else
	{return(1);}

}

