//  There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))


#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int median(int A[], int Ast, int Aen)
{
	if((Aen - Ast)%2 ==0)
		return(A[(Ast+Aen)/2]);
	else
		return((A[(Ast+Aen)/2] + A[((Ast+Aen)/2)+1])/2);
}

int medianTwoSortArr(int A[], int B[], int Ast, int Aen, int Bst, int Ben)
{
	
	while(((Aen-Ast)!=1) && ((Ben-Bst)!=1))
	{
		int m1, m2;
		m1 = median(A, Ast, Aen);
		m2 = median(B, Bst, Ben);
		if(m1 < m2)
		{
			Ast = floor((float(Ast) + float(Aen))/2);
			Ben = ceil((float(Bst) + float(Ben))/2);
		}
		else
		{
			Aen = ceil((float(Ast) + float(Aen))/2);
			Bst = floor((float(Bst) + float(Ben))/2);
		}
	}
	return((max(A[Ast], B[Bst]) + min(A[Aen], B[Ben]))/2);
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
	int n;
	cin>>n;
	int A[n], B[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];

	printArray(A,(n));
	printArray(B,(n));

	cout<<"\nANSWER : "<<medianTwoSortArr(A,B,0,n-1,0,n-1)<<endl;

	return 1;
}

	










	


