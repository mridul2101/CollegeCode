#include<iostream>
using namespace std;

int main()
{
	long long int n,k,min=100000000000,max=0,count=0,flag=0;
	cin>>n>>k;
	long long int a[n][2];
	
	for(int i=0;i<n;i++)	
	{
		cin>>a[i][0]>>a[i][1];
		if(min>a[i][0])
		   min=a[i][0];
		if(max<a[i][1])
		   max=a[i][1];
	}

	for(int i=min;i<=max;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=a[j][0] and i<=a[j][1])
			{
				count++;
			}
			if(count==k)
			{
			    flag=1;break;
			}
		}
	if(flag==1)
	{cout<<i<<endl;break;}
	}
return(0);
}
	

	
	


