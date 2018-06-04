#include<iostream>
using namespace std;

int main()
{
	
	long long int fib[100000],fib1[100000],t;
	long int value;
	int m=3;	
	cin>>t;
	fib[0]=1;
	fib[1]=2;
	fib[2]=4;
	fib1[0]=1;
	fib1[1]=2;
	fib1[2]=3;
	
	if(t<=10000 && t>=1)
	{
		for(long long int j=0;j<t;j++)
		{
		  cin>>value;
		  if(value>=1 && value<=100000)
		  {
		   if(value>m)
		   {
			for(long long int i=m;i<value;i++)
			{
			 fib[i]=(fib[i-1]%1000000007+fib[i-2]%1000000007+fib[i-3]%1000000007)%1000000007;
 	       	     	fib1[i]=(fib1[i-1]%1000000007+fib1[i-2]%1000000007)%1000000007;		
			}m=value;
		   }
		
	
		cout<<((fib[value-1]*fib1[value-1])%1000000007)<<endl;
	}}}	
	return(0);
}
