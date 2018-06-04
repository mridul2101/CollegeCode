#include<iostream>
using namespace std;

#include<stdlib.h>
#include<string.h>

int check(char[]);
long long int lcm_cal(long long int,long long int);
long long int lcm(long long int,long long int);
long long int gcd(long long int,long long int);

int main()
{	
	char *a;
        a=(char*)malloc(512*sizeof(char*));
	cin>>a;
	if(!check(a))
	   {cout<<"ERROR: INVALID TYPE INPUT\n";exit(1);}
	
	long long int n=0;
	n=atoi(a);
	delete(a);	
	if(n<=0 || n>30)
		{cout<<"ERROR: INVALID RANGE INPUT\n";exit(1);}
	

	lcm_cal(n,n-1);
	return(0);
}

long long int lcm_cal(long long int a,long long int b)
{
	if(b==1)
	{
		cout<<lcm(a,b);return(1);
	}

	return(lcm_cal(lcm(a,b),b-1));
}

long long int lcm(long long int a,long long int b)
{
   return((a*b)/gcd(a,b));
}	

long long int gcd(long long int a,long long int b)
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

