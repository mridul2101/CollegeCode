#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char *p;
	{
		char ch[10];strcpy(ch, "PJ");
		p = ch;
			cout<<p<<endl;	
	}
	cout<<p<<endl;
	return 1;
}

