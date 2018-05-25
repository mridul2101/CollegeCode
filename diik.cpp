#include<iostream>
using namespace std;

void maxk(int a[], int n, int k)
{
	int max, min;
	max = a[n-1];
	min = a[0];
	int Hash[max + 1];
	for(int i =0;i<max+1;i++) Hash[i] = 0;

	int flag = 0;

	for(int i = 0;i<n;i++)
	{
		Hash[a[i]] = 1;
		if(((a[i] - k) >= 0) && (Hash[(a[i] - k)] != 0))
		{
			flag = 1;cout<<a[i]<<"  "<<a[i]-k<<endl;
			break;
			
		}
	}
	if(flag == 0)
		cout<<"NO\n";
	return;
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i =0 ;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	maxk(a,n,k);
	return 1;
}

