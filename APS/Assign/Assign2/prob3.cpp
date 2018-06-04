/*Given an array A, you now know how to find a Sub-Array sum i.e., A[i]+ A[i+1] + ... + A[j]. A sub-array is defined by its starting index i and its ending index j ( 0 <= i <= j < N ). Can you find the maximum sum of a sub-array.

Input:
First line contains N, number of elements in the array ( 1 <= N <= 100000 ).
Second line contains N integers in range [-10^4,10^4], separated by spaces.

Output:
Print the maximum sum possible for a sub-array of A. (Followed by a '\n' which is just for a newline, no need to display)


Sample Cases:

Input:
4
1 -2 1 2

Output:
3\n

Explanation:
Sum(0..0) = 1, Sum(0..1) = -1, Sum(0..2) = 0, Sum(0..3) = 2, . . . , Sum(2..3) = 3, . . . , Sum(3,3) = 2
Among all possible SubArray sums, Sum(2..3) = 3 has the maximum value.
*/



#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],flag=0;
	for(int i=0;i<n;i++)
	{cin>>a[i];
	  if(a[i]>0)
	     flag=1;
	}
	
	if(flag!=1)
	{int max=a[0];
	   for(int i=1;i<n;i++)
	   {
		if(max<a[i])
		  max=a[i];
	  }
	cout<<max<<endl; return(0);
	}


	int max=0,p=max;

	for(int i=0;i<n;i++)
	{
		if((a[i]+p)>max || (a[i]+p)>=0)
		   {
			p+=a[i];
			
		   }
		else if((a[i]+p)<0)
		{
			p=0;
			if(max<p) max=p;
			//var=i;
		}
		if(max<p)
		  max=p;
	}
	cout<<max<<endl;
return(0);
}	


