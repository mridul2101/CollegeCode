//Pascal Triangle

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j] = 0;

	arr[0][0] = 1;
	for(int i=n-1;i>0;i--)
		cout<<" ";
	cout<<arr[0][0]<<endl;				
	for(int i=1;i<n;i++)
	{
		for(int k=n-i-1;k>0;k--)
		{
			cout<<" ";
		}
		for(int j=0;j<=i;j++)
		{
			if(j == 0)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % 100000007;
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;
}


