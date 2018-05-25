#include<iostream>
using namespace std;

class A
{
	int k;
	static int s;
	public:
	A()
	{	k = 10;
		cout<<" HEYS\n\n";
	}
	int setK(int p)
	{
		k = p;
	}
	int getK()
	{
		return k;
	}
	static int getS()
	{
		return s;
	}
	friend ostream& operator << (ostream&, A);
	
	
};

ostream& operator << (ostream &out, A a)
{
	cout<<"OPERATOR : "<<a.k<<endl;
	return out;
}


int A::s = 5;

int main()
{
	A a;
	cout<<a.getK()<<"  "<<a.getS()<<endl;
	cout<<a.getK()<<"  "<<A::getS()<<endl;

	A a1,a2;
	a1.setK(100);
	a2 = a1;
	cout<<a2.getK()<<endl;


	cout<<a1;

		
	return 1;
}
