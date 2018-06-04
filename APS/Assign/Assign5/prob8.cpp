/*
 Getting bored by doing lots of programming!!!

Let's do some interesting stuff by installing multiple operatins systems in the desktop .Not physically but in code :)
Your task is to install 'N' Operating Systems in desktop.
To install each OS you have to install 'P' packages in the system.But the problem with this is some packages are dependent on other packages.In that case first you need to resolve dependency, than only you can install other packages.

Your task is to just give the order of packages in which it should be installed for each OS. and if you are finding any difficulty in installing OS just say 'Not Possible'.

Note : Not possible is expected if packages are missing,not when you are not able to get answer. :P Input
first line contains number of OS. N
second line contains number of packages for 1st OS. P (numbering of packages are from 1 to P - both are included)
Third line contains number of dependencies. D
D dependencies for 1st OS.
same information for other Operating Systems

In dependency : A B means package B is dependent on package A.
Output
Each line contains output for each OS.
If installation is possible than print order of installation.In case of multiple order give lexicographically least order.
If installation is not possible than print "Not Possible" (without quotes).
Constraint
Max no of Operating Systems : 3
Max no of packages per Os : 40
Time Limit : 1s.
Sample Case 1:

Input:

2 
3
2
2 1
1 3
3
3
1 2
2 3 
3 1


Output:
2 1 3_
Not Possible\n

Sample Case 2:

Input:

1
4
6
1 2
1 4
1 3
2 3
4 3
4 2


Output:
1 4 2 3_\n

* In output _ is to indicate a blank space after output.
** No extra spaces or lines will be present in the input, though they may appear here in sample cases dues to html formatting 

*/


#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int d,distance;
};

int maximum=0,maximum1=0;

int main()
{
	int n,m;	
	cin>>n>>m;
	int src,dest;	
	int adj_mat[n][n],maxm[n];
	for(int i=0;i<n;i++)
	{maxm[i]=0;
		for(int j=0;j<n;j++)
		adj_mat[i][j]=0;	
	}
	for(int i=0;i<m;i++)
	{
		cin>>src>>dest;
		adj_mat[src][dest]=1;
		adj_mat[dest][src]=1;
		
	}
	

	for(int i=0;i<n;i++)
	{	
		stack<node>stk;
		int flag=0,flag1=0;
		struct node np,n1;
		int visit[n],distan[n];
		for(int k=0;k<n;k++)
			{distan[k]=1000;visit[k]=0;}
		np.d=i;
		np.distance=0;
		stk.push(np);
		visit[i]=1;
		distan[i]=0;
		while(!stk.empty())	
		{	
			
			np=stk.top();
			
			stk.pop();
			for(int j=0;j<n;j++)
			{
				if(adj_mat[np.d][j]==1 && ( visit[j]==0 || distan[j]>=(np.distance+1)))
				{
					flag=1;					
					n1.d=j;
					n1.distance=np.distance+1;
					stk.push(n1);
					visit[j]=1;
					distan[j]=np.distance+1;
				}
				if (distan[j]>=(np.distance+1) )
				{flag1=1;}
				
			}
			
		}
		if(flag==1)
			{
				for(int k=0;k<n;k++)
				{
					if(maxm[i]<distan[k] && distan[k]!=1000 && flag1==1)
						maxm[i]=distan[k];
				}
				/*temp_max=np.distance+1;
				if(temp_max > maximum && (flag1==1) )
					{maximum=temp_max;}
				*/
			}
					
	}

	for(int i=0;i<n;i++)
	  {
		if(maximum<maxm[i])
			maximum=maxm[i];
	  }
		
	cout<<maximum<<endl;
}

	






