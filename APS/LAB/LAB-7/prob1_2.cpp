#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	double xa,ya,xb,yb,xc,yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	double t1,t2;

		t1=atan2((yb-ya),(xb-xa));
		if(t1<0 and t1!=-1.5708)
		t1+=(2*3.1415);
		
		t2=atan2((yc-yb),(xc-xb));
		if(t2<0 and t2!=-1.5708)
		t2+=(2*3.1415);
		
	if(xa<xb && xb==xc && ya==yb && yb>yc)
	  cout<<"RIGHT\n";
	else
	if(xa<xb && xb<xc && ya<yb && yc<yb)
	   cout<<"RIGHT\n";
	else
	if(xa<xb && xb<xc && ya>yb && yc>yb)
	   cout<<"LEFT\n";
	else
	if(xa==xb && xc>xb && ya>yb && yb==yc)
	  cout<<"LEFT\n";
	else		


	if(t2<t1)
		cout<<"RIGHT"<<endl;
	else if(t2>t1)
		cout<<"LEFT"<<endl;
	else if(t1==t2)
		cout<<"TOWARDS"<<endl;
	//cout<<"t1 "<<t1<<"t2 "<<t2<<endl;
	return 0;
}





