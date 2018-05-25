/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;

	int a[m][n],temp[m][n];
	for(int i =0;i<m;i++)
		for(int j = 0;j<n;j++)
			cin>>a[i][j];

	for(int i =0;i<m;i++)
		for(int j = 0;j<n;j++)
			temp[i][j] = 0;

	temp[0][0] = a[0][0];

	for(int i = 1;i<m;i++)
	{
		temp[0][i] = a[0][i] + temp[0][i-1];
	}
	for(int i = 1;i<n;i++)
	{
		temp[i][0] = a[i][0] + temp[i-1][0];
	}



	for(int i = 1; i<m; i++)
	{
		for(int j = 1 ;j<n;j++)
		{
			temp[i][j] = a[i][j] + min(temp[i-1][j], min(temp[i][j-1], temp[i-1][j-1]));
		}
	}	

	for(int i = 0;i<m;i++)
	{
		for(int j =0;j<n;j++)
			cout<<temp[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl<<endl;
	return 1;
}







