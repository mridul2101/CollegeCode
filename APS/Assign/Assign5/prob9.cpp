/*
 Superman has to go from Bombay To Goa and he needs your help. To travel from Bombay to goa one has to go via several cities. However, many cities have been inhabited by zombies () and superman wants to avoid those cities. Moreover, he wants to reach Goa travelling via as less number of cities as possible so as to save fuel of his Bajaj Scooter which gives very less average. As Always APS students are Ready To Help. Even ACP Pradyuman is ready to tell you which all cities have been inhabited by zombies.

The Information you have: A Map diagram M x N (Each cell a city). Number of cities inhabited by Zombies T.Co-ordinates of Bombay(bi,bj), Goa(gi,gj) and cities inhabited by Zombies.

The Information you have to provide: Shortest Distance from Bombay To Goa avoiding Zombie Cities. If there is no such path possible then say so by printing -1.

Superman has Always Helped Others, now it is our time to pay back.
Input:
First line contains M and N. Second line contains bi and bj. Third line contains gi and gj. Fourth line contains T Next T lines give the co-ordinates of Zombies Cities i and j.

Output:
Print the answer in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:
1 <= M,N <= 200
Time Limit : 1s
Sample Case 1:

Input:

3 3
0 0
1 2
2
0 1
1 1


Output:
5\n


Sample Case 2:

Input:

2 2
0 0
1 1
2
0 1
1 0


Output:
-1\n

** No extra spaces or lines will be present in the input, though they may appear here in sample cases dues to html formatting 

*/

#include<iostream>
#include<queue>
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
	int b1,b2,g1,g2,visit[n][m],dist[n][m],zomb[n][m];
	cin>>b1>>b2>>g1>>g2;
	
	int t;
	cin>>t;


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			{visit[i][j]=zomb[i][j]=0;dist[i][j]=10000000;}
	}

	int ax,bx;
	for(int i=0;i<t;i++)
	{
		cin>>ax>>bx;
		zomb[ax][bx]=1;
	}

	node np,n1;
	np.a=b1;np.b=b2;
	visit[np.a][np.b]=1;
	dist[np.a][np.b]=0;
	stk.push(np);	
		
	while(!stk.empty())
	{	
		n1=stk.front();
		stk.pop();			
			
		if(n1.b!=0)
		{
			if(visit[n1.a][n1.b-1]==0 && zomb[n1.a][n1.b-1]==0)
			{
				visit[n1.a][n1.b-1]=1;
				np.a=n1.a;np.b=n1.b-1;
				stk.push(np);
				if(dist[n1.a][n1.b]<dist[n1.a][n1.b-1])
					dist[n1.a][n1.b-1]=dist[n1.a][n1.b]+1;
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[n1.a][np.b]<<endl;
			}
		}
		
		if(n1.a!=0)
		{
			if(visit[n1.a-1][n1.b]==0 && zomb[n1.a-1][n1.b]==0)
			{
				visit[n1.a-1][n1.b]=1;
				np.a=n1.a-1;np.b=n1.b;
				stk.push(np);
				if(dist[n1.a][n1.b]<dist[n1.a-1][n1.b])
					dist[n1.a-1][n1.b]=dist[n1.a][n1.b]+1;
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[n1.a][np.b]<<endl;
			}
		}

		if(n1.a!=(n-1))
		{
			if(visit[n1.a+1][n1.b]==0 && zomb[n1.a+1][n1.b]==0)
			{
				visit[n1.a+1][n1.b]=1;
				np.a=n1.a+1;np.b=n1.b;
				stk.push(np);
				if(dist[n1.a][n1.b]<dist[n1.a+1][n1.b])
					dist[n1.a+1][n1.b]=dist[n1.a][n1.b]+1;
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[n1.a][np.b]<<endl;
			}
		}
		
		if(n1.b!=(m-1))
		{
			if(visit[n1.a][n1.b+1]==0 && zomb[n1.a][n1.b+1]==0)
			{
				visit[n1.a][n1.b+1]=1;
				np.a=n1.a;np.b=n1.b+1;
				stk.push(np);
				if(dist[n1.a][n1.b]<dist[n1.a][n1.b+1])
					dist[n1.a][n1.b+1]=dist[n1.a][n1.b]+1;
				//cout<<np.a<<"  "<<np.b<<"     "<<dist[n1.a][np.b]<<endl;
			}
		}

		
	}
	if(visit[g1][g2]==0)
		cout<<"-1"<<endl;
	else					
		cout<<dist[g1][g2]<<endl;
	
	return(0);
}



