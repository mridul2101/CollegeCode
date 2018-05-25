/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150′th ugly number.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ugly[n];

	ugly[0] = 1;
	int i2, i3, i5;
	i2 = i3 = i5 = 0;

	for(int i = 1;i<n;i++)
	{
		int min_t = min(ugly[i2]*2, min(ugly[i3]*3, ugly[i5]*5));
		ugly[i] = min_t;
		if(min_t == ugly[i2]*2)
			i2++;
		if(min_t == ugly[i3]*3)
			i3++;
		if(min_t == ugly[i5]*5)
			i5++;
	}

	for(int i = 0;i<n;i++)
		cout<<ugly[i]<<"  ";
	cout<<endl<<endl;
	return 1;
}

