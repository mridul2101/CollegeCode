// An element in a sorted array can be found in O(log n) time via binary search. But suppose I rotate the sorted array at some pivot unknown to you beforehand.


#include<iostream>
using namespace std;

int missNumber(int A[], int n)
{
	int value, sum = 0;
	for(int i=0;i<n-1;i++)
		sum += A[i];
	int sum1 = (n*(n+1))/2;

	value = sum1 - sum;	
	return value;
}	

int main()
{
	int n;
	cin>>n;
	int A[n-1];
	for(int i=0;i<n-1;i++)
		cin>>A[i];


	cout<<"\nANSWER : "<<missNumber(A,n)<<endl;

	return 1;
}

	










	


