#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;



void swap(char str[], int i, int j)
{
	int t;
	t = str[i];
	str[i] = str[j];
	str[j] = t;
	return;
}
//BACKTRACKING
void permute(char str[], int i, int len)
{
	if(i == len) 
	{	
		cout<<str<<endl;	
		return;
	}
	else
	{
		for(int j = i;j < len ; j++)
		{
			swap(str, i, j);
			permute(str, i+1, len);
			swap(str, i, j);
		}
	}
	return;
}

//USING STL
void permute_stl(char str[])
{
	sort(str, str+strlen(str));
	cout<<str<<endl;
	while(next_permutation(str,str+strlen(str)))
	{
		cout<<str<<endl;
	}
	return;
}

int main()
{
	char str_n[1000] ;
	cin>>str_n;
	char str[1000];
	strcpy(str,str_n);

	permute_stl(str);

	//permute(str, 0, strlen(str));
	
	return(0);
}



