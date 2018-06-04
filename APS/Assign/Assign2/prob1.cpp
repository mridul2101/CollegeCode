/*You are given a set of digits, your task is to find the maximum integer that you can make from these digits. The made number must be divisible by 2, 3, 5 without a residue. It is permitted to use not all digits from the set, it is forbidden to use leading zeroes.
Each digit is allowed to occur in the number the same number of times it occurs in the set.

Input
A single line contains a single integer n (1 ≤ n ≤ 1000) — the number of digits in the set. 
The second line contains n digits, the digits are separated by a single space.

Output
On a single line print the answer to the problem. If such number does not exist, then you should print -1.

Sample test case:
Input
11
3 4 5 4 5 3 5 3 4 4 0

Output
5554443330
*/


#include<iostream>
using namespace std;

int main()
{
   int n,flag=0,sum=0;
   cin>>n;
   int a[n];
  
   for(int i=0;i<n;i++)
   {
	cin>>a[i];sum+=a[i];
	if(a[i]==0)
	   flag=1;
   }

	if(flag==0)
	{
	   cout<<"-1"; cout<<endl;return(0);
	}
	if(sum<=2)
	{
	   cout<<"0";cout<<endl;
	   return(0);
	}		

   for(int i=1;i<=n-1;i++)
   {
	for(int j=0;j<n-i;j++)
	{
	    if(a[j]>a[j+1])
	    {
		int t;
		t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
	    }
	}
    }flag=0;


  int index[2]={-1},mode,j=0,i,count=0; 
  if(sum%3==0)
     {
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}cout<<endl;return(0);
     }
  else
     mode=sum%3;


   
  if(mode==2 and flag!=1)
  {
	for(i=1;i<n;i++)
	{
		if((a[i]%3)==2)
	        {
		    index[j]=i;flag=2;break;
		}
	}
	for(i=1;(i<n and flag!=2 and count!=2);i++)
	{
		if((a[i]%3)==1)
		{
		   count++;index[j]=i;j++;
		   flag=3;
		}
	}
   }
   else if(mode==1 and flag!=1)
	{
	     for(i=1;i<n;i++)
	     {
		if((a[i]%3)==1)
	        {
		    index[j]=i;flag=2;break;
		}
	     }
	for(i=1;(i<n and flag!=2 and count!=2);i++)
	{
		if((a[i]%3)==2)
		{
		   count++;index[j]=i;j++;
		   flag=3;
		}
	}
  }	
int tp=0;
if(flag==2)
{int f=0;
	for(int i=n-1;i>=0;i--)
	{
	    if(a[i]==0 and f==0)
		continue;
	    else if((i!=index[0]))
		  {cout<<a[i];f=1;tp=1;}
	}
}				
else
	if(flag==3)
	{int f=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==0 and f==0)
				continue;
	    		else	if((i!=index[0]) && (i!=index[1]))
			{  cout<<a[i];f=1;tp=1;}
		}
	}
	else
	   cout<<"-1";		
if(tp==0)
 cout<<"0";
cout<<endl;
return(0);
}
















