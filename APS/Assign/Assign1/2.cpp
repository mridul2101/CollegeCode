#include<iostream>
using namespace std;

#include<stdlib.h>
#include<string.h>

int check(char[]);
int gcd(int ,int );
int main()
{
    char *a,*b;
     a=(char*)malloc(512*sizeof(char*));
     b=(char*)malloc(512*sizeof(char*));
    
    cin>>a;cin>>b;
    if(!check(a) || (!check(b)))
	{cout<<"ERROR: INVALID TYPE INPUT\n";exit(1);}
    int n,k;
    n=atoi(a);
    k=atoi(b);
    delete(a);
    delete(b);
    if(n>1000 || k>1000)
	{cout<<"ERROR: INVALID RANGE INPUT\n";exit(1);}

    for(int i=3;i<=n;i++)
    {   cout<<i<<":1";
	for(int j=2;j<k;j++)
	{
		if (gcd(i,j)==1)
		  cout<<","<<j;
	}cout<<endl;
    }
}	
int gcd(int a,int b)
{
    while(b!=0 )
    {
	int t;
	t=b;
	b=a%b;
	a=t;
    }
   
	return(a);
    
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
















