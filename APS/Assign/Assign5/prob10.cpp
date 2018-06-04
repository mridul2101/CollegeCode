/*
 Tom & Jerry.

Tom and Jerry are in a park which has a grid like structure.Every Cell in the park is attached with some delay, Tom on a way to Jerry needs to wait for time T(i,j), if Tom visits T(i,j). Tom wants to catch Jerry by taking the path which has minimum delay.

Lets say Tom starts at (tx,ty) in a grid, by taking a step Tom can only reach (tx,ty+1),(tx,ty-1),(tx+1,ty),(tx-1,ty).

Delay corresponding to Tom's Starting position and Jerry's Destination(jx,jy) are included.
 
Your task is to find the minimum amount of time that Tom will take to reach Jerry.

Input:

The first input line contains two ints N M.
Next N lines contains M ints representing  T(i,j).
Next Line contains two ints tx ty indicating Tom's starting position..
Next Line contains two ints jx jy indicating Jerry's position.
All values are space seperated.

Output:
 
Minimum Time.

Constraints:
 
0 <= N,M <= 100.
0 <= tx,jx <= N-1
0 <= ty,jy <= M-1

Time Limit:  1s

Sample Case 1:



Input:
 
4 5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
0 0
3 4
 
Output:
24\n
 
Explanation:

(0,0)--->(0,1)--->(0,2)--->(1,2)--->(2,2)--->(3,2)--->(3,3)--->(3,4):
  0     +     3     +      1    +      4    +      5    +      4    +      2    +       5       =   24

*/


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int a,b;
};

int minimum=10000000;
queue<node>stk;

int main()
{
	int n,m;	
	cin>>n>>m;
	int wt[n][m];
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
		cin>>wt[i][j];

	int b1,b2,g1,g2,visit[n][m],dist[n][m];
	cin>>b1>>b2>>g1>>g2;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			{visit[i][j]=0;dist[i][j]=10000000;}
	}


	node np,n1;
	np.a=b1;np.b=b2;
	visit[np.a][np.b]=1;
	dist[np.a][np.b]=wt[b1][b2];
	stk.push(np);	

	while(!stk.empty() )
	{	
		n1=stk.front();
		stk.pop();			
			
		if(n1.b!=0)
		{
			if(visit[n1.a][n1.b-1]==0)
			{
				//visit[n1.a][n1.b-1]=1;
				np.a=n1.a;np.b=n1.b-1;
				
				if((wt[n1.a][n1.b-1]+dist[n1.a][n1.b])<dist[n1.a][n1.b-1])
					{stk.push(np);dist[n1.a][n1.b-1]=dist[n1.a][n1.b]+wt[n1.a][n1.b-1];}
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[np.a][np.b]<<endl;
			}
		}
		
		if(n1.a!=0)
		{
			if(visit[n1.a-1][n1.b]==0)
			{
				//visit[n1.a-1][n1.b]=1;
				np.a=n1.a-1;np.b=n1.b;
				
				if((wt[n1.a-1][n1.b]+dist[n1.a][n1.b])<dist[n1.a-1][n1.b])
					{stk.push(np);dist[n1.a-1][n1.b]=dist[n1.a][n1.b]+wt[n1.a-1][n1.b];}
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[np.a][np.b]<<endl;
			}
		}

		if(n1.a!=(n-1))
		{
			if(visit[n1.a+1][n1.b]==0)
			{
				//visit[n1.a+1][n1.b]=1;
				np.a=n1.a+1;np.b=n1.b;

				
				if((wt[n1.a+1][n1.b]+dist[n1.a][n1.b])<dist[n1.a+1][n1.b])
					{stk.push(np);dist[n1.a+1][n1.b]=dist[n1.a][n1.b]+wt[n1.a+1][n1.b];}
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[np.a][np.b]<<endl;
			}
		}
		
		if(n1.b!=(m-1))
		{
			if(visit[n1.a][n1.b+1]==0)
			{
				//visit[n1.a][n1.b+1]=1;
				np.a=n1.a;np.b=n1.b+1;
				if((wt[n1.a][n1.b+1]+dist[n1.a][n1.b])<dist[n1.a][n1.b+1])
					{stk.push(np);dist[n1.a][n1.b+1]=dist[n1.a][n1.b]+wt[n1.a][n1.b+1];}
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[np.a][np.b]<<endl;
			}
		}

		
	}
	
	cout<<dist[g1][g2]<<endl;
	
	return(0);
}



