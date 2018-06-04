/*iven a M × M array of positive and negative integers, find the sub-rectangle with the largest sum. A sub-rectangle is any contiguous sub-array of size 1 × 1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. The input to the program is the value of M followed by the array itself.

Input:
First line contains M ( 1 <= M<= 100 )
Next M lines contains M elements each, describing the matrix A ( -100 <= A[i][j] <= 100 )

Output:
The Maximum Sum (Followed by a '\n' which is just for a newline, no need to display)

Sample Cases:

Input:
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

Output:
15\n
Explanation: The SubMatrix (1,0)-(3,1) has the maximum sum of 15.

*/

#include<iostream>
using namespace std;

int main()
{
   int m,max,flag=0;
   cin>>m;
   int a[m+1][m+1],temp_sum; 

   for(int i=0;i<=m;i++)
     a[i][0]=a[0][i]=0;
   max=0;
   for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	  {int t;
		cin>>t;
	   if(t>0)
	     flag=1;
	   a[i][j] = t+a[i-1][j]+a[i][j-1]-a[i-1][j-1];

	}

   if(flag!=1)
   {
	  max=a[1][1];
	   for(int i=1;i<=m;i++)
	   { 
		for(int j=1;j<=m;j++)
		{
		   if(max<a[i][j])
		     max=a[i][j];
		}
	  }
	cout<<max<<endl; return(0);
   }

  max=0;
  for(int i1=1;i1<=m;i1++)
  {
     for(int j1=1;j1<=m;j1++)
     { 
	  for(int i2=i1;i2<=m;i2++)
	  {
	 	for(int j2=j1;j2<=m;j2++)
		{
   		   temp_sum = a[i2][j2]- a[i1-1][j2]-a[i2][j1-1]+a[i1-1][j1-1];
		   if(temp_sum>max)
		       max=temp_sum;	
		}
	}
   }
}

cout<<max<<endl;
return(0);
}




















