#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int indexzero = -1;
	for(int i=0;i<n;i++){
		if(a[i] == 0 && indexzero == -1)
			indexzero = i;
		else if(a[i] != 0 && indexzero != -1)
			{
				a[indexzero] = a[i];
				a[i] = 0;
				indexzero = i;	
			}
	}
	for(int i =0;i<n;i++)
		cout<<a[i]<<"  ";
}


