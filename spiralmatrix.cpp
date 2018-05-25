#include<iostream>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int arr[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	/*for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                        cout<<arr[i][j];*/

	int a,b,c,d;
	a = b = 0;
	c = m;
	d = n;
	while(a<c && b<d){
		for(int i=b;i<d;i++)
			cout<<arr[b][i]<<"  ";
		a++;
		for(int i=a;i<c;i++)
			cout<<arr[i][d-1]<<"  ";
		d--;

		if(a<c){
			for(int i=d-1;i>=b;i--)
				cout<<arr[c-1][i]<<"  ";
			c--;
		}	
		if(b<d){
			for(int i=c-1;i>=a;i--)
				cout<<arr[i][b]<<"  ";
			b++;
		}

	}cout<<endl;
	return 0;

}

