#include<iostream>
using namespace std;
#include<math.h>

int main()
{
	int t,flag=0;
	cin>>t;
	long long int a[t];
	long int p;
	for(int i=0;i<t;i++)
		cin>>a[i];
	
	for(int i=0;i<t;i++)
	{flag=0;
	p=(long int)sqrt(a[i]);
	long int j=0,k=p,sqr;
		while(j<=k)
		{
		 sqr=j*j+k*k;
		  if((sqr)<a[i])
		  {	j++;}
		  else if((sqr)>a[i])
			{ k--;}
		       else if((sqr)==a[i])
				{flag=1;break;}
			
		}
	if(flag==0)
	   cout<<"NO\n";
	else 
	   cout<<"YES\n";
	}
}
		   
