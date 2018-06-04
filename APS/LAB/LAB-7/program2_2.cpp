#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	double n,m;
	cin>>n>>m;
	if(n==m)
	{
		printf("%.4lf\n",0.0);	
		return 0;
	}
	//double p=10000.0;
	//double in=p/n;
	//double fi=p/(n+m);
	//double move=(in-fi)/m;
	double move;
	if((long long int)(n+m)%2!=0)
	 move=2500/(m+n)*n;
	else
	 move=2500/(n)*(n-1);
	printf("%.4lf\n",move);

	return 0;
}
