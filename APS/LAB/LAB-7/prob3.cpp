#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	long long int k,n,q;
	
	cin>>k>>n;
	long long int array[100004]={0},c[100004]={0};
	long long  int temp;
	for(long long int i=0;i<n;i++)
	{
		
		cin>>temp;
		array[temp]++;
		array[temp]=array[temp]%1000000007;
	}
	c[0]=array[0]%1000000007;
	for(long long int i=1;i<=k;i++)
	{
		c[i]=(c[i-1]+array[i])%1000000007;
	}
	cin>>q;
	long long int sum=0,a,b;
	while(q--)
	{
		cin>>a>>b;
		if(a==0)
			sum=(sum+c[b])%1000000007;
		else
			sum=((sum+c[b])%1000000007-c[a-1])%1000000007;
	
	}
	cout<<sum<<endl;
	
	return 0;
}
