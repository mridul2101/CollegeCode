/* There is a Heritage Marathon in Hyderabad which starts from Charminar at 5.30AM sharp on 9th-Oct-2011 and ends at Golconda Fort. Dhaval is going to take part in it but he lands in a problem. So he called Dhrumil and ask the route by which he can get the maximum energy drinks on the way. Dhrumil as usual Google's Marathon site( http://www.hyderabadheritagemarathon.com ) and founds a map of the route. The map is of Grid strucure(size N X N) and units of Energy Drink available at each square grid were seen on the map. Moreover Dhrumil knew Dhaval being lazy will move only right and down in map so Dhrumil and other TAs being more lazy decided to ask you guys to help Dhaval by solving this problem asap.

Formally Speaking:
Given a N x N grid, where each cell contains some units of Energy Drink. Dhaval starts at cell (1,1) and wants to reach the cell (N,N). From a cell (i,j) he can either move one cell down or right, i.e., to cell (i+1,j) or (i,j+1).
Find the maximum number of units of Energy Drinks he can collect along a path from (1,1) to (N,N).

Constraints:
1 <= N <= 1000
0 <= units[i][j] < 100

Input:
N
(Following N lines will have N X N integer values)

Output:
Maximum_units(new line)

Time Limit : 1s

Sample Case:

Input:
3
2 8 10
4 1 4
2 3 9

Output:
33\n

Explanation:
(1,1)--->(1,2)--->(1,3)--->(2,3)--->(3,3)
  2      +    8     +     10   +      4    +     9      =  33

*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n][n];

	for(int i=0;i<n;i++)
	{
	   for(int j=0;j<n;j++)
	   {
		cin>>a[i][j];
		if(i==0 && j==0)
			continue;
		if(i==0)
		{
			a[i][j]+=a[i][j-1];
		}
		else	if(j==0)
			  a[i][j]+=a[i-1][j];
			else 
			{
				if(a[i-1][j]>a[i][j-1])
				{	a[i][j]+=a[i-1][j];}
				else
				{	a[i][j]+=a[i][j-1];}
			}
	   }
	}

	cout<<a[n-1][n-1]<<endl;	


	return(0);
}
		


