/*Here is a very easy linear recurrence for you to solve,

F(k) = 2.F(k-1) + 5.F(k-2) + 3

Initial Cases: F(0) = 1, F(1) = 2.

Input: Given n and M
Constraints: 0 <= n <= 10^9 , 2 <= M <= 10^9
Output: find the value of F(n) % M

Sample Case:
1)
Input:
4 15
Output:
2\n

2)
Input:
3 40
Output:
37\n
*/

#include<iostream>
using namespace std;

int main()
{
	long long int n,m,t,ans;
	cin>>n>>m;
	
	if(n==0)
	{cout<<"1"<<endl;return(0);}
	if(n==1)
	{cout<<"2"<<endl;return(0);}
	if(n==2)
	{cout<<(12%m)<<endl;return(0);}

	long long int a[3][3]={{2,5,3},{1,0,0},{0,0,1}},c[3][3];
	long long int b[3][3]={{2,5,3},{1,0,0},{0,0,1}};
	//long long int x[3][3]={{2,5,3},{1,0,0},{0,0,1}};
	t=n-2;
	while(true)
	{
		if(t==1 || t==0)
			break;
		if(t%2!=0)
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{c[i][j]=0;
				   for(int k=0;k<3;k++)
				   {
					c[i][j]=(c[i][j]+(b[i][k]*a[k][j])%m)%m;				
				   }
				}
			}
			for(int i=0;i<3;i++)
			   for(int j=0;j<3;j++)
				b[i][j]=c[i][j];			
		}
		t/=2;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{c[i][j]=0;
			   for(int k=0;k<3;k++)
			   {
				c[i][j]=(c[i][j]+(a[i][k]*a[k][j])%m)%m;				
			   }
			}
		}
			for(int i=0;i<3;i++)
			   for(int j=0;j<3;j++)
				a[i][j]=c[i][j];	
		
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{c[i][j]=0;
		   for(int k=0;k<3;k++)
		   {
			c[i][j]=(c[i][j]+(b[i][k]*a[k][j])%m)%m;				
		   }
		}
	}
	for(int i=0;i<3;i++)
	   for(int j=0;j<3;j++)
		b[i][j]=c[i][j];			


			
	ans=(((2*b[0][0])%m+b[0][1])%m+b[0][2])%m;
	cout<<ans<<endl;
	
return(0);
}


