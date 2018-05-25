#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

int main()
{
	int a,b;

	a = 5;
	b = 10;

	cout<<a<<"  "<<b<<endl;
	swap(a,b);
	cout<<a<<"  "<<b<<endl;
	
	return 1;
}	

