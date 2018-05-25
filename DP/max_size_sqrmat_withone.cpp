/*


Maximum size square sub-matrix with all 1s

Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

For example, consider the below binary matrix.

 
   0  1  1  0  1 
   1  1  0  1  0 
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0

The maximum square sub-matrix with all set bits is

    1  1  1
    1  1  1
    1  1  1

*/


#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int m, n;
	cin>>m>>n;
	int input[m][n];
	for(int i =0 ;i<m;i++)
		for(int j = 0;j<n;j++)
			cin>>input[i][j];

	int temp[m][n];
	
	for(int i=0;i<n;i++)
		temp[0][i] = input[0][i];
	for(int i=0;i<m;i++)
		temp[i][0] = input[i][0];

	for(int i = 1;i<m;i++)
	{
		for(int j = 1; j<n;j++)
		{
		    if(input[i][j] == 1)
			temp[i][j] = min(temp[i-1][j-1], min(temp[i][j-1], temp[i-1][j])) + 1;
		    else
			temp[i][j] = 0;
		}
	}
	
	int max_p=input[0][0], x=0 , y=0;
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(max_p < temp[i][j])
			{	
				max_p = temp[i][j];
				x = i;y = j;
			}				
		}
	}	
	
	for(int i = x - temp[x][y] +1; i <= x; i++)
	{
		for(int j = y - temp[x][y] +1; j <= y; j++)
				cout<<input[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl<<endl;
	return 1;
}
	









