#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int sumfind(char a[], int st, int en)
{
	char tempchar[en-st+1];
	for(int i = st, j = 0;i<=en;i++,j++)
		tempchar[j]=a[i];
	

	int temp = atoi(tempchar);
	return temp;	
	
}

void value(char a[], char temp[], int st, int en, int *c)
{
	int temp1 = 0;

		
	/*temp1 = sumfind(temp, st, st);
	cout<<temp1<<endl;
	
	if((temp1 % 9) == 0)
	{
		cout<<st<<" -  "<<st<<endl;
		(*c)++; 
	}	
	*/
	for(int i = st;i<=en;i++)
	{
		temp[i] = a[i];
		temp1 = sumfind(a, st, i);
		//cout<<temp1<<"  "<<temp1<<endl;
		if((temp1 % 9) == 0)
		{	
		//	cout<<st<<" -- "<<en<<endl;
			(*c)++; 
		}
	}		
	
	return;
}

int main()
{
	int n;
	cin>>n;
	char a[n];
	for(int i =0;i<n;i++)
		cin>>a[i];
	int c = 0;
	for(int i = 0;i<n;i++)
	{
		char temp[n];
		temp[i] = a[i];
		value(a, temp, i, n-1, &c);
	}
	cout<<"ANS : "<<c<<endl;
	return 1;
}

