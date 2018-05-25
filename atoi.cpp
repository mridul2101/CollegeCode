#include<iostream>
using namespace std;

int atoii(char a[], int n);
int main()
{
	char a[]={'1','0','1','0'};
	cout<<atoii(a,4)<<endl;
	return 1;
}

int atoii(char a[], int n)
{
	int p=0,pow=1;
	for(int i=n-1;i>=0;i--)
	{	
		p+=(pow*((a[i]-'0')));cout<<p<<endl;
		pow*=10;
	}
	return(p);
}

