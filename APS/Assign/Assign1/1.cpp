#include<iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>
#include<string.h>

int check(char[]);

int main()
{
     char *a;
     a=(char*)malloc(512*sizeof(char*));
     cin>>a;
     if(!check(a))
	   {cout<<"ERROR: INVALID TYPE INPUT\n";exit(1);}

     long int n;long long int sum=0;
     n=atoi(a);
     delete(a);
     if(n<1 || n>500000)
	{cout<<"ERROR: Invalid RANGE Input.\n";return(0);}
     for(int i=2;i<=((int)sqrt(n));i++)
     {
	if(n%i==0)
	   {
		sum+=((i)+(n/i));
		if((float)i==sqrt(n))
		   {sum-=i;}
	   }
	
     }
	sum++;
	cout<<sum<<endl;
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

