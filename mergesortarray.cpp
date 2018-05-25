// There are two sorted arrays. First one is of size m+n containing only m elements. Another one is of size n and contains n elements. Merge these two arrays into the first array of size m+n such that the output is sorted.

//NA means -1

#include<iostream>
using namespace std;

void mergeArray(int A[], int B[], int p, int n)
{
	int pt = 0;
	int i,k;
	for(i = p-n, k=0;i<p && k<n;)
	{
		if(A[i]<B[k])
		{
			A[pt++] = A[i++];
		}
		else
		{
			A[pt++] = B[k++];
		}
	}
	while(k<n)
		A[pt++] = B[k++];

	return;
}	

void moveToEnd(int A[], int p)
{
	int k = p-1;

	for(int i=p-1;i>=0;i--)
	{
		if(A[i] != -1)
		{	int temp;
			temp = A[i];
			A[i] = -1;			
			A[k] = temp;
			k--;
		}	
	}
	return;
}

void printArray(int A[], int p)
{
	cout<<endl;
	for(int i=0;i<p;i++)
		cout<<A[i]<<"  ";
	cout<<endl;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int A[m+n], B[n];
	for(int i=0;i<m+n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];

	moveToEnd(A,(m+n));
	printArray(A,(m+n));
	
	mergeArray(A,B,m+n,n);

	cout<<"\nANSWER : ";
	printArray(A,(m+n));

	return 1;
}

	










	


