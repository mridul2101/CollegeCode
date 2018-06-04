/*Given N and K, find the smallest and the largest positive integers, each with exactly N digits and having exactly K distinct digits ( 0 - 9 ). Note that the answer should have exactly K distinct digits, for eg: 1124214 has only 3 distinct digits 1, 2 and 4. Leading zeros are not allowed, for eg: 0112 is not allowed.

Input:
Only one line, containing N K ( 1 <= N <= 18 and 1 <= K <= 10 ). Input is given such that the answer will always exist.

Output:
Print the smallest and largest integers, separated by exactly one space (Followed by a '\n' for new line, no need to display)

Time Limit: 1s

Sample:

Input:
2 2
Output:
10 98\n

Input:
3 3
Output:
102 987\n
*/



#include<iostream>
using namespace std;

int main()
{
	int n,k,t_k,flag=0;
	cin>>n>>k;

	t_k=1;
	flag=n-k;
	for(int i=0;i<n;i++)
	{
	   if(k==1 and n==1)
	   {
		cout<<"0";
		break;
	   }
	   if(k==1)
	   {
		cout<<"1";
		continue;
	   }
	   if(k==n)
	   {   
		if(i!=1)
		{cout<<t_k;t_k++;}
		else
		cout<<"0";		
	   continue;}

	   if(n>k)
	   {
		if(i==1)
			{cout<<"0";}				
		else if(flag!=0 and i>1)
			{cout<<"0";flag--;}							
			else
			{
			cout<<t_k;t_k++;				
			}
			continue;
	   }		

	}
cout<<" ";
	t_k=9;
	flag=n-k;
	for(int i=0;i<n;i++)
	{
	   if(k==n)
	   {   
		cout<<t_k;t_k--;		
	   	continue;
	   }

	   if(n>k)
	   {
		if(flag!=0)
		{
			cout<<t_k;flag--;
		}							
		else
		{
			cout<<t_k;t_k--;				
		}
		continue;
	   }		

	}
cout<<endl;
return(0);
}



