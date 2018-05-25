//Merge Sort

#include<iostream>
using namespace std;

void merging(int A[], int left, int mid, int right)
{
	int i,j;
	i = left;
	j = mid + 1;

	int B[right - left + 1];
	int k = 0;
	while(i <= mid && j <= right)
	{
		if(A[i] <= A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while(i <= mid)
		B[k++] = A[i++];
	
	while(j <= right)
		B[k++] = A[j++];
	
	for(int i = left, j = 0; i<= right ;i++, j++)
		A[i] = B[j];

}

void mergesort(int A[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left + right)/2;

		mergesort(A, left, mid);
		mergesort(A, mid+1, right);
		
		merging(A, left, mid, right);
		
	}
}


int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i = 0;i<n;i++)
		cin>>A[i];

	cout<<"\nBEFORE SORTING : ";
	for(int i = 0;i<n;i++)
		cout<<A[i]<<"  ";

	mergesort(A, 0, n-1);

	cout<<"\nAFTER SORTING : ";
	for(int i = 0;i<n;i++)
		cout<<A[i]<<"  ";
	cout<<endl<<endl;
	return 1;
}

