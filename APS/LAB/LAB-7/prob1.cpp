#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	double xa,ya,xb,yb,xc,yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	
	double t1,t2;
	if(xb-xa==0)
		t1=90;
	else 
	{
		t1=atan((yb-ya)/(xb-xa));
	}
	if(xc-xb==0)
		t2=90;
	else 
	{
		t2=atan((yc-yb)/(xc-xb));
	}
	
	if(yb>0)
	{
		if(yb<=yc)
		{
		if(t2<t1)
			cout<<"RIGHT"<<endl;
		else if(t2>t1)
			cout<<"LEFT"<<endl;
		else if(t1==t2)
			cout<<"TOWARDS"<<endl;
		}
	
		else
		{
			if(t2>t1)
				cout<<"RIGHT"<<endl;
			else if(t2<t1)
				cout<<"LEFT"<<endl;
			else if(t1==t2)
				cout<<"TOWARDS"<<endl;
		}
	
	}
	else
	{
	if(yc>yb)
	{
	if(t2<t1)
		cout<<"RIGHT"<<endl;
	else if(t2>t1)
		cout<<"LEFT"<<endl;
	else if(t1==t2)
		cout<<"TOWARDS"<<endl;
	}
	else
	{
	
	if(t2>t1)
		cout<<"RIGHT"<<endl;
	else if(t2<t1)
		cout<<"LEFT"<<endl;
	else if(t1==t2)
		cout<<"TOWARDS"<<endl;
	}
	}
	//cout<<"t1 "<<t1<<"t2 "<<t2;	
	return 0;
}



