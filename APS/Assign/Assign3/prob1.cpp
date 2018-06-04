/*You are already done with parenthesization problem. Now this time you will be given an string which can have 6 characters '(', ')','{','}','[',']'

You have to check whether the string is consistent or not ?

The definition for being consistent is as follows:
1. An empty string is consistent.
2. If STR is consistent, then each of (STR), [STR], {STR} is also consistent.
3. If S1 and S2 are both consistent, then S1S2 (the concatenation of the two) is also consistent.

All of these strings are consistent: (), (){}, and ({}[]); But none of these: )(, {()[, nor [](

Your program will be tested on one or more data sets(N).Each data set is described on a single line. No string has more than 1000 characters.

Input:
Line one contains number of testcases N followed by N strings.

Output:
for each test case print YES\n if string is a consistent else NO\n if not consistent.

Constraints:
1 <= N <= 50
string length <= 1000
Time Limit : 1s

Sample Input:

Input:
4
(){}[]
({}[])
({)}[]
{[]({[]})}

Output:
YES
YES
NO
YES\n

Explanation: By using the rules you can prove string 1,2 & 4 are consistent but not string 3.
*/





#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int t,flag=0;
	cin>>t;
	char str[1001],ch;	
	while(t--)
	{	
		flag=0;
		cin>>str;
		stack<char> stk;
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='{' or str[i]=='(' or str[i]=='[')
				stk.push(str[i]);
			if(str[i]=='}')
			{
				if(stk.empty())
				{flag=1;break;}
				ch=stk.top();
				stk.pop();
				if(ch!='{')
				{flag=1;break;}
			}
			if(str[i]==')')
			{
				if(stk.empty())
				{flag=1;break;}
				ch=stk.top();
				stk.pop();
				if(ch!='(')
				{flag=1;break;}
			}
			if(str[i]==']')
			{
				if(stk.empty())
				{flag=1;break;}
				ch=stk.top();
				stk.pop();
				if(ch!='[')
				{flag=1;break;}
			}
		}
		if(!stk.empty())
			flag=1;	
		if(flag==1)
		 cout<<"NO"<<endl;
		else
		 cout<<"YES"<<endl;
	}
return(0);
}

	


