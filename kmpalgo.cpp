/*
KMP String Matching Algo
and strstr function
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int* CreatePrefixTable(char P[], int m)
{
	int *F;
	F = new int[m];

	F[0] = 0;
	int i,j;
	i = 1;
	j = 0;
	while(i<m)
	{
		if(P[i] == P[j])
		{
			F[i] = j+1;
			i++;
			j++;
		}
		else if(j > 0)
		     {
			j = F[j-1];
			
		     }
		     else
		     {
			F[i] = 0;
			i++;
		     }
	}
	return F;
}

int KMPAlgo(char T[], int n, char P[], int m)
{
	int *F;
	F = CreatePrefixTable(P, m);

	int i,j;
	i = j = 0;
	
	while(i < n)
	{
		if(T[i] == P[j])
		{
			if(j == m-1)
				return (i-j);
			i++;
			j++;
		}
		else if(j > 0)
		     {
			j = F[j-1];
			
		      }
		     else i++;
	}
	return -1;
}


int main()
{
	int n,m;
	cin>>n>>m;
	char T[n],P[m];

	cin>>T>>P;
	int flag = KMPAlgo(T, n, P,m) ;
	if(flag != -1)
		cout<<"String Match at pos : "<<flag<<endl;
	else
		cout<<"String doesnt match at all"<<endl;

	cout<<strstr(T,P)<<" at index : "<<strlen(T)-strlen(strstr(T,P))<<endl;
	return 0;
	
}









