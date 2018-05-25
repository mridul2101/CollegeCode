#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];

	int b[n][n], c[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j] = a[j][n-i-1];
			c[i][j] = a[n-j-1][i];
		}
	}
	for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                        cout<<a[i][j]<<"  ";
                cout<<endl;
        }
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<b[i][j]<<"  ";
		cout<<endl;
	}	
	cout<<endl;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                        cout<<c[i][j]<<"  ";
                cout<<endl;
        } 

}
