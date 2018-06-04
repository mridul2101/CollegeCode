#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	double n,m;
   while(scanf("%lf %lf",&n,&m)!= -1)
   {
	double sum=0;
	if(n==m)
	{
		cout<<"0.0000"<<endl;
		continue;
	}
	double a[int(n)];
	a[0]=0;
	for(int i=1;i<n;i++)
	{
		a[i]=i*(10000/n);
	}
//	for(int i=0;i<n;i++)
//	cout<<a[i]<<"  ";	
	
	double b[int(n+m)];
	b[0]=0;
	for(int i=1;i<(n+m);i++)
	{
		b[i]=i*(10000/(n+m));
	}
/*	cout<<endl;
	for(int i=0;i<(n+m);i++)
	cout<<b[i]<<"  ";	
	cout<<endl;
*/	
	for(int i=0;i<n;i++)
	{
		double min=100000.0;
		for(int j=0;j<(n+m);j++)
		{
			if(a[i]>b[j])
			{
				if((a[i]-b[j])<min)
				  min=a[i]-b[j];
				
			}
			else
			{
				if((b[j]-a[i])<min)
				  min=b[j]-a[i];
			}
			if(b[j]>=a[i])
			  break;
		}//cout<<min<<endl;
		sum+=min;
	}
	printf("%.4lf\n",sum);
	}
	return 0;
}
