#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[1000],*s;
	cin>>str;
	int axis[20]={-1},i=0,count=0;
	s=strtok(str,",");
	while(s!=NULL)
	{
		count++;
		axis[i]=atoi(s);i++;
		s=strtok(NULL,",");
	}	

	for(int i=0;i<20;i++)
	{
		if(i>=count)
		    axis[i]=-1;
		cout<<axis[i]<<" ";
	}

	int a[50][count]={-1},pt=49;
	for(int i=0;i<count;i++)
	{

	
}

















