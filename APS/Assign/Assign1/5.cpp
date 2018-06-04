#include<iostream>
using namespace std;

#include<stdlib.h>
#include<string.h>

int check(char[]);

int main()
{
	char *c,*b;
        c=(char*)malloc(512*sizeof(char*));
        b=(char*)malloc(512*sizeof(char*));	
	cin>>c>>b;

	if(!check(c) || (!check(b)))
	   {cout<<"ERROR: INVALID TYPE INPUT\n";exit(1);}

	int n,m;
	n=atoi(c);
    	m=atoi(b);
	delete(c);
	delete(b);

	if(m<0 || n<0 ||m>1000 || n>1000 )
	{cout<<"ERROR: Invalid RANGE Input";exit(1);}	
	if(m>n)
	{cout<<"ERROR: n should be greater than m";exit(1);}		
	if(n==m || m==0)
	{cout<<"1";return(0);}
	

	long long int a[n+1][n];
	
	
	a[0][0]=1;
	if(m>(n-m))
	{m=n-m;}
	for(int i=1;i<=n;i++)
	{       a[i][0]=a[i][i]=1;
		for(int j=1;j<i;j++)
		{
        	   a[i][j]=(((a[i-1][j-1])+(a[i-1][j]))%1000000007);
		}
	}	
	cout<<a[n][m];
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

