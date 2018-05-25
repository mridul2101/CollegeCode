//Given an array of positive integers. All numbers occur even number of times except one number which occurs odd number of times. Find the number in O(n) time & constant space.

#include<iostream>
using namespace std;

int oddOccur(int A[], int n)
{
	int max = 0;
	int value = 0;

	for(int i = 0;i<n;i++)
		value = value ^ A[i];


	return value;
}			


int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];


	cout<<"\nANSWER : "<<oddOccur(A,n)<<endl;

	return 1;
}

	










	


