#include<stdio.h>

int main()
{
	long int n,k;
	scanf("%ld",&n);
	int a[n],p;
	long long int sum=0;
	long int q;
	for(k=0;k<n;k++)
	{
		scanf(" %d",&p);
		if(k!=0)
		   a[k]=a[k-1]+p;
		else
		   a[k]=p;
	}	
	scanf("%ld",&q);
	
	long int i[q],j[q];
	
	for(k=0;k<q;k++)
	{
		scanf("%ld%ld",&i[k],&j[k]);
		if(i[k]!=0)		
		sum=sum+a[j[k]]-a[i[k]-1];
		else
		sum=sum+a[j[k]];
	}		
		
	printf("%lld\n",sum);
	return(0);
}

