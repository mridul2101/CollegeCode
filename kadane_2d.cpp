#include<iostream>
using namespace std;

int n,m;
int kadane2D(int**, int, int, int);
int kadane1D(int*, int);


int main()
{
	//CHECK FOR ALL NEGATIVE NUMBER

	cin>>n>>m;
	
	int arr[n][m],**ext, flag = 0;

	ext = new int*[n+1];
	for(int i = 0 ;i<=n;i++)
		ext[i] = new int[m+1];	
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{	cin>>arr[i][j];
			if(arr[i][j] > 0)
				flag = 1;
		}


	for(int i=0;i<=m;i++)
		ext[0][i] = 0;
	for(int i = 0;i<=n;i++)
		ext[i][0] = 0;

	int max = arr[0][0];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ext[i][j] = arr[i-1][j-1];
			if(max < ext[i][j])
				max = ext[i][j];
		}
	if(flag == 0)
	{
		cout<<"\nMAXIMUM VALUE = "<<max<<endl<<endl;	
		return 1;
	}
	for(int i = 1; i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			ext[i][j] += ext[i-1][j];
		}
	}

	/*for(int i=0;i<=n;i++)
	{	for(int j=0;j<=m;j++)
			cout<<ext[i][j]<<"  ";
		cout<<endl;
	}
	*/
	

	max = kadane2D(ext,max,n+1,m+1);	

	cout<<"\nMAXIMUM VALUE = "<<max<<endl<<endl;	
	return 1;
}
	
int kadane1D(int *temp, int m)
{
	int max, temp_max = 0;
	max = temp[0];
	for(int i = 0;i<m;i++)
	{
		if(max < temp[i])
			max = temp[i];
	}

	for(int i = 0;i<m;i++)
	{
		temp_max += temp[i];
		if(temp_max < 0)
		{
			temp_max = 0;
			continue;
		}
		if(max < temp_max)
			max = temp_max;
	}
	return max;	
}	
	

int kadane2D(int **ext, int max, int n, int m)
{
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<i-1;j++)
		{
			int *temp;
			temp = new int[m];
			for(int k = 0 ;k<m;k++)
				temp[k] = (ext[i][k] - ext[j][k]);
			
			int max_temp;				
			max_temp = kadane1D(temp, m);
			
			if(max < max_temp)
				max = max_temp;
		}
	}
	return max;
}


