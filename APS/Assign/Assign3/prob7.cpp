/*You are given n(<=8) weights, w1,w2, • • • ,wn. Find all distinct weight measurements that you can make using a common balance and the given weights. For example, assume that you are given weights of 1, 3, and 5 units. You can weigh all measures from 1 to 9 units as:
• 1 = 1
• 2 = 3 − 1
• 3 = 3
• 4 = 3 + 1
• 5 = 5
• 6 = 5 + 1
• 7 = 5 + 3 − 1
• 8 = 5 + 3
• 9 = 5 + 3 + 1
You can subtract a specific weight you have, by adding it along with item to be measured. Your input will contain the number of weights you have, followed by the weights themselves. You need to output all the possible weights you can measure in the increasing order. You should not repeat any measures.

 Input:
First Line contains N(number of distinct weights)(N<=8). Next line will have N distinct weights separated by space.
Output:
list of distinct weights possible in increasing order followed by ‘\n’

Input:
3
1 3 5
Output:
1 2 3 4 5 6 7 8 9
*/




#include<iostream>
using namespace std;
#include<stdlib.h>
#include<math.h>

int comp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,p,q,cum_sum=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{cin>>a[i];cum_sum+=a[i];}
	qsort(a,n,sizeof(int),comp);
	p=pow(3,n);
	int s[3]={-1,0,1},b[p][n],s1=0,sum[10000]={0};
	q=p;
	for(int i=0;i<n-1;i++)
	{
	   q=q/3;s1=0;
	   for(int j=0;j<p;j++)
	   { 
		if(j%q==0)
		{
			b[j][i]=s[s1++];
			s1=s1%3;
		}
		else
			b[j][i]=b[j-1][i];	
	  }
	}
	s1=0;
	for(int i=0;i<p;i++)
	{
		b[i][n-1]=s[s1++];
		s1=s1%3;
	}	
	
	int a1=0;
	for(int i=0;i<p;i++)
	{	sum[a1]=0;
		for(int j=0;j<n;j++)
		{
		   sum[a1]+=(b[i][j]*a[j]);
		}a1++;
	}a1++;

	qsort(sum,a1,sizeof(int),comp);			
	
	for(int i=1;i<a1;i++)
	{
		if(sum[i]>0 && sum[i]!=sum[i-1] && sum[i]<=cum_sum)
			cout<<sum[i]<<" ";
	}
	
	cout<<endl;
	return(0);
}
	




	

