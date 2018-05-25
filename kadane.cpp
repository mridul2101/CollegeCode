#include<iostream>
using namespace std;

int main()
{
	int a[] = {5,3,-10,3,1,-5,6,4};

	int sum, temp;
	sum = temp = 0;
	
	//Check for all negative numbers 

	for(int i = 0;i<8;i++)
	{
		temp += a[i];
		if(temp < 0)
		{
			temp = 0; 
			continue;
		}
		if(sum < temp)
		{
			sum = temp;
		}
	}

	cout<<sum<<endl;
	return (1);
}

