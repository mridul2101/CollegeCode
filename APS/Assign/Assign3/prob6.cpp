/* Having taken APS course and attended 4 labs already, you soon relaized that you need more luck in addition to problem solving skills :). The astrologer you met in Indranagar told you that 3, 7, and 9 are your lucky digits. A lucky number for you is a number that contains only your lucky digits in it. For eg: 3, 79, 933 etc., are lucky, where as 372, 91, 70 are not. Given a large integer N, count the number of lucky numbers in [1,..,N]

Input : Only one line having an integer N ( 1 <= N <= 10^14 )
Output : Number of lucky numbers in [1,..,N] followed by a '\n' ( just print '\n', no need to display on screen )
Time Limit : 2s

Sample cases :

Input:
78
Output:
8\n
Explanation:
The lucky numbers not more than 78 are 3, 7, 9, 33, 37, 39, 73, 77 

Input:
1000
Output:
39\n 
*/


#include<iostream>
using namespace std;
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	char str[1000];
	cin>>str;
	int l;
	long long int sum=0;	
	l=strlen(str);
	int s[l];
	sum=3*(pow(3,l-1)-1)/2;
	//a=atoi(str);
	for(int i=0;str[i]!='\0';i++)
	{
		s[i]=str[i]-'0';
	}	
	int j=0;
	for(int i=0;i<l;)
	{
		
	if(s[j]<3)
	{
	    cout<<sum<<endl;		
	    return(0);
	}
	if(s[j]>3 and s[j]<7)
	{
	    sum+=pow(3,l-j-1);
	    cout<<sum<<endl;		
	    return(0);
	}
	if(s[j]>7 and s[j]<9)
	{
	    sum+=(2*pow(3,l-j-1));
	    cout<<sum<<endl;		
	    return(0);
	}
	if(s[j]==3)
	{
		if(j==l-1)
		{
			sum++;
			cout<<sum<<endl;		
		        return(0);
		}
		j++;
		continue;
	}
		
	if(s[j]==7)
	{
		if(j==l-1)
		{
			sum=sum+2;
			cout<<sum<<endl;		
		        return(0);
		}
		
		sum+=pow(3,l-j-1);
		j++;
		continue;
	}
	if(s[j]==9)
	{
		if(j==l-1)
		{
			sum=sum+3;
			cout<<sum<<endl;		
		        return(0);
		}
	
		sum+=(2*pow(3,l-j-1));
		j++;
		continue;
	}			   
}
return(0);
}







