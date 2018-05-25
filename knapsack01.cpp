#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int w[n], b[n];
	for(int i=0;i<n;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
		cin>>b[i];

	int M;
	cin>>M;
	int table[n+1][M+1];
	
	for(int i = 0 ;i<n+1;i++)
	{
		for(int j = 0;j<M+1;j++)
		{
			if(i==0 || j==0)
				table[i][j] = 0;
			else if(w[i-1] > j)
				table[i][j] = table[i-1][j];
			     else
				table[i][j] = max(table[i-1][j], b[i-1]+table[i-1][j-w[i-1]]);

		}
	}
	for(int i =0;i<n+1;i++)
	{
		for(int j = 0;j<M+1;j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}
	cout<<table[n][M]<<endl;
	return 1;
}
	
