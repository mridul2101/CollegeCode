#include<iostream>
using namespace std;

int main()
{
	int a=5, b=10;

	a = a xor b;
	b = a xor b;
	a = a xor b;
	
	cout<<a<<"  "<<b<<endl;
	return 0;
}

