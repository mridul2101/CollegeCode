#include<iostream>
using namespace std;
#include<stdlib.h>

int main()
{
	int p,q,r,s;
	cin>>p>>q;
	int A[p][q][2];
	for(int i=0;i<p;i++)
	   for(int j=0;j<q;j++)
	      for(int k=0;k<2;k++)
	      	cin>>A[i][j][k];

	cin>>r>>s;
	int B[r][s][2];
	for(int i=0;i<r;i++)
	   for(int j=0;j<s;j++)
	     for(int k=0;k<2;k++)
	       cin>>B[i][j][k];

	if(q==r)
	{

	int Ans[p][s][2];
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<s;j++)
		{Ans[i][j][0]=0;Ans[i][j][1]=0;
		   for(int k=0;k<q;k++)
		   {
			Ans[i][j][0]+=((A[i][k][0]*B[k][j][0])-(A[i][k][1]*B[k][j][1]));
			Ans[i][j][1]+=((A[i][k][0]*B[k][j][1])+(A[i][k][1]*B[k][j][0]));
		   }
		}
	}

	for(int i=0;i<p;i++)
	   for(int j=0;j<s;j++)
	        {	
		  cout<<Ans[i][j][0]<<"+i"<<Ans[i][j][1]<<"\n";;
		}
	}
return(0);
}


	
	

	
