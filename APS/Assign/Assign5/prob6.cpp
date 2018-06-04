/*
 Given the map of Lakshadweep, find the number of islands in it. You will be given a rectangular map of R rows and C columns. Each cell is either land ( denoted by '#' ) or water ( denoted by '.' ). Two cells are adjacent to eachother, if they share a side. So there can be at most 4 neighbors to each cell ( diagonal cells are not treated adjacent ). Now, an island is a piece of connected land. Find the number of islands present. See the example cases for more clarity.
Input:
First line contains R and C. Next R lines give the description of the island.

Output:
Print the answer in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:
1 <= R, C <= 200
Each cell is either a '.' or a '#'
Time Limit : 1s
Sample Case 1:

Input:


3 4

...#

##.#

#..#


Output:
2\n



Sample Case 2:

Input:


3 3

..#

#..

.##


Output:
3\n


** No extra spaces or lines will be present in the input, though they may appear here in sample cases dues to html formatting 

*/

#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int a,b;
};

int count=0;

int main()
{
	int n,m;	
	cin>>n>>m;
	char a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='.')
				continue;
			stack<node>stk;
			node n,n1;
			n.a=i;n.b=j;
			stk.push(n);
			a[n.a][n.b]='.';
			while(!stk.empty())
			{
				n1=stk.top();
				
				stk.pop();
				if(a[n1.a][n1.b-1]=='#' && (n1.b!=0))
				{
				   n.a=n1.a;n.b=n1.b-1;
				   stk.push(n);
				   a[n.a][n.b]='.';				
				}			
				if(a[n1.a-1][n1.b]=='#'&& (n1.a!=0))
				{
				   n.a=n1.a-1;n.b=n1.b;
				   stk.push(n);a[n.a][n.b]='.';
				}
				if(a[n1.a][n1.b+1]=='#'&& (n1.b!=m-1))
				{
				   n.a=n1.a;n.b=n1.b+1;
				   stk.push(n);a[n.a][n.b]='.';				
				}	
				if(a[n1.a+1][n1.b]=='#'&& (n1.a!=m-1))
				{
				   n.a=n1.a+1;n.b=n1.b;
				   stk.push(n);a[n.a][n.b]='.';				
				}
			}
			count++;
		}
	}
	cout<<count<<endl;
}



				
	
