#include<stdio.h>
//long long int fibonicci(long long int,long long int,long long int);
//long long int c=0;
int main()
{
	int t,i;
	scanf("%d",&t);
	long long int a[t],p=1000001;
	long long int b[p];
	b[0]=1;
	b[1]=1;
	for(i=0;i<t;i++)
	{
		scanf(" %lld",&a[i]);
	}

	for(i=2;i<p;i++)
	{	
	   b[i]=(b[i-1]+b[i-2]) % 1000000007;
	} 
	for(i=0;i<t;i++)
	{	
		printf("%lld\n",b[a[i]]);
	}
return(0);
}





	

