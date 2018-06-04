/*Given a,b,c,N find number of multiples of a or b or c which are less than or equal to N.  

Constraints:
1 <= a,b,c <= 10^6, 1 <= N <= 10^18

Input:
First line contains T, number of test cases
Next T lines each contain a,b,c,N all separated by space.

Output:
Just output the result for each test case.

Example:

Input:
1
2 4 6 10

Output:
5
*/




#include<iostream>
using namespace std;

long long int gcd(long long int,long long int );
int main()
{

  long long int t,i=1;
  cin>>t;
  long long int a,b,c,n,sum,g,g1,l,l1,f1,f2,f3;

  while(i<=t)
  {sum=0;
	cin>>a>>b>>c>>n;
	if((a==0) | (b==0) | (c==0))
	 {
	   cout<<"0\n"; i++;
	   continue;
	 }

	f1=  (n/((a*b)/gcd(a,b)));

	f2=(n/((c*b)/gcd(c,b)));
	f3=(n/((a*c)/gcd(a,c)));

	sum+=((n/a)+(n/b)+(n/c));
	sum-=(f1+f2+f3);

	g=gcd(a,b);
	l=(a*b)/g;
	
	g1=gcd(l,c);
	l1=(l*c)/g1;
	
	sum+=(n/l1);
	cout<<sum<<endl;
	i++;
  }
  return(0);
}	

long long int gcd(long long int a,long long int b)
{
    while(b!=0 )
    {
	int t;
	t=b;
	b=a%b;
	a=t;
    }
   
	return(a);
    
}


