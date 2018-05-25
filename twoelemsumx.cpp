//Given an array A[] and a number x, check for pair in A[] with sum as x

#include<iostream>
using namespace std;

bool sumTwoElemX(int A[], int n, int x)
{
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(max<A[i]) 
			max = A[i];
	}
	
	int hash[max+1];
	for(int i=0;i<=max;i++)
		hash[i] = -1;
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		hash[A[i]] = A[i];
		if(((hash[A[i]] + (hash[x-A[i]])) == x) && (A[i] != (x-A[i])))
		{
			cout<<"\n"<<hash[A[i]]<<"  "<<hash[x-A[i]]<<endl;
			flag = true;
			break;
		}
	}
	return flag;
}			


int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int x;
	cin>>x;

	cout<<"\nANSWER : "<<sumTwoElemX(A,n,x)<<endl;

	return 1;
}

	










	


