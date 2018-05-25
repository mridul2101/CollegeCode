//Print the first non-repeated character in a string.

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int hash[300] = {0};
		char input[100000],ch;
		cin>>input;
		for(int i=0;i<strlen(input);i++)
		{
			hash[(int)input[i]]++;
		}
		for(int i=0;i<strlen(input);i++)
		{
			if(hash[(int)input[i]] == 1)
			{
				ch = input[i];
				break;
			}
		}

		cout<<endl<<ch<<endl<<endl;
	}
	return(0);
}


