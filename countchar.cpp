#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char b[1000];
	cin>>b;

	int count = 1;
	int index = 1;

	for(int i = 1;i<strlen(b);i++)
	{
		if(b[i] == b[i-1])
		{
			count++;
		}
		else{
			int p = count;int temp[1000];int k = 0;
			while(p!=0)
			{				
				temp[k++] = char((p%10)+48);
				p /= 10;
			}	
			for(k = k-1;k>=0;k--)
				b[index++] = temp[k];

			b[index++] = b[i];
			count = 1;
		}
	}
	int temp[1000];int k = 0;int p =count;
	while(p!=0)
	{				
		temp[k++] = char((p%10)+48);
		p /= 10;
	}	
	for(k = k-1;k>=0;k--)
		b[index++] = temp[k];
	
	b[index] = '\0';
	cout<<"ANS : "<<b<<endl;
	return 1;
}

		

