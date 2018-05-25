//Parenthesis Matching

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	char str[1024];
	cin>>str;
	stack<char> stk;
	int flag = -1;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i] == '{')
		{
			stk.push('{');
		}
		else if(str[i] == '}')
		     {
			if(stk.empty())
			{
				flag = 0;
				break;
			}
			else
			{
				char ch = stk.top();
				stk.pop();
				if(ch != '{')
				{
					flag = 0;
					break;
				}
			}
		     }
	}
	if(!stk.empty() || flag == 0)
	{
		cout<<"\n WRONG ONE\n\n";
	}
	else
	{
		cout<<"\n CORRECT ONE\n\n";
	}
	
	return 1;
}		


