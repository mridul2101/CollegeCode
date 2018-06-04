/*Colour Time!!!!

You are given some N number of Blocks. And there are some M number of links between them. Your task is to find whether you can colour all the blocks using only two colours i.e Black or White such that no two neighbouring blocks have same colour.

Input:
First Line contains number of Test cases.
Following Line have test cases
For each test cases : First line has number of blocks 'N' and number of links 'M'.
Followed by the M links.


Output:
Print YES or NO for each test cases, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:
1 <= T <= 10
1 <= N <= 100
0 <= M <= NC2
Time Limit : 1s

Sample Case 1:

Input:

2
5 6
1 3
1 4
1 5
2 3
2 4
2 5
4 4
1 3
1 4
1 2
2 3


Output:
YES\n
NO\n


*/

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,src,dest;
		cin>>n>>m;
		int adj_mat[n][n],color[n];
		
		for(int i=0;i<n;i++)
		{color[i]=0;		
			for(int j=0;j<n;j++)
			adj_mat[i][j]=0;
		}
		for(int i=0;i<m;i++)
		{
			cin>>src>>dest;
			adj_mat[src-1][dest-1]=1;
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{	
			for(int j=0;j<n;j++)
			{
				if(adj_mat[i][j]==1)
				{
					if((color[i]==0) && (color[j]==0))
					{
						color[i]=1;color[j]=2;
					}
					if((color[i]==0) && (color[j]!=0))
					{
						if(color[j]==1)
							color[i]=2;
						else
							color[i]=1;
					}			
					if((color[i]!=0) && (color[j]==0))
					{
						if(color[i]==1)
							color[j]=2;
						else
							color[j]=1;
					}
					if((color[i]!=0) && (color[j]!=0))
					{
						if(color[i]==color[j])
						{   flag=1;
						    break;}
					}
					
				}
			}
			if(flag==1)
			  break;
		}
		if(flag==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
return(0);
}







