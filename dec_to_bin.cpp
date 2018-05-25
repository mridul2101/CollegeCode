#include<iostream>
#include<vector>
#include<iterator>
#include<stdlib.h>
using namespace std;

int main()
{
	string s = "10";

	char x[10];

	s.copy(x,3);

	int p = atoi(x);

	int temp = p;
	
	vector<int> out;

	vector<int>::iterator it;
	while(temp != 0)
	{
		it = out.begin();
		out.insert(it, temp % 2);
		temp /= 2;

	}


	for(it = out.begin();it!=out.end();it++)
		cout<<*it;
	cout<<endl<<s<<endl;
	return 0;
}
	

	

