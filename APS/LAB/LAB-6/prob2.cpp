#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int compare (const void *a, const void *b)
{
  return ( *(int*)a - *(int*)b );
}
void find_k_occur(long long int *start_r,long long int *end_r,long long int *a,long long int *b,long long int *c);

long long int inp,d[2000][2];
long long int n,p,k=0;
	

int main()
{
	cin>>n>>inp;
	p=2*n;
	long long int start_r[n],end_r[n],a[p],b[p],c[p];
	for(int i=0;i<n;i++)
	{
		cin>>start_r[i]>>end_r[i];
	}			
	for(int i=0;i<p;i++)
	{a[i]=b[i]=c[i]=d[i][0]=d[i][1]=0;}

	for(int i=0;i<n;i++)
	{
		a[2*i]=start_r[i];	
		a[2*i+1]=end_r[i];	
	}
	qsort (a,p,sizeof(long long int), compare);
	
	find_k_occur(start_r,end_r,a,b,c);	
	
	return(0);
}


void find_k_occur(long long int start_r[],long long int end_r[],long long int a[],long long int b[],long long int c[])
{
	long long int length=0;
	for(int i=0;i<p;i++)
	{
		if(a[i+1]!=a[i])
		{
			b[length++]=a[i];
		}
	}

	d[0][0]=d[0][1]=0;
	for(long long int i=0;i<length;i++)
	{
	  c[i]=0;	
	for(int j=0;j<n;j++)
	 {
	   if((b[i]>=start_r[j]) && (b[i]<=end_r[j]))
		c[i]++;
	 }
	}

	for(long long int i=1;i<length;i++)
	{
	   d[i][1]=b[i]-b[i-1]-1;
	   if(b[i]-b[i-1]==1)
	   {
		d[i][0]=0;
	   }
	   else
	   {
		d[i][0]=0;
		for(int j=0;j<n;j++)
		{	
			if(( (b[i]-1) > start_r[j]) && ((b[i]-1)<end_r[j]))
			  d[i][0]++;
		}
	    }
	}
	long long int t=0;
	
	for(long long int i=0;i<length;i++)
	{
		long long int prev=t;
		long long int var;
		t+=(d[i][0]*d[i][1]);
		if(t>=inp)
		{
		   var=(long long int)ceil((double)(inp-prev)/d[i][0]);		
		   cout<<(b[i-1]+var)<<endl;
		   break;
		}
		t+=c[i];
		if(t>=inp)
		{
			cout<<b[i]<<endl;			
			break;
		}
	}
	return;
}








