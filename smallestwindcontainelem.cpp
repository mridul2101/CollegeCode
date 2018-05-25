#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;


int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);

	int l1, l2;
	l1 = str1.length();
	l2 = str2.length();

	int hash1[256] = {0},hash2[256]={0};

	for(int i =0;i<l2;i++)
	{
		hash1[str2[i]]++;
	}
	
	int start, end, min_len = max(l1,l2)+1;
	start = end = -1;
	
	for(int i=0;i<l1;i++)
	{
		if(hash1[str1[i]] > 0) 
		{
			if(start == -1)
				start = i;
			hash2[str1[i]]++;
			int flag = 0;
			for(int j =0;j<256;j++)
			{
				if(hash2[j] < hash1[j] )
				{
					flag = 1;break;			
				}
			}
			if(flag == 0)
			{
				end = i;
				if(min_len > end-start+1)
					min_len = end-start+1;
				break;
			}			
		}
	}
	for(int i = end+1;i<l1;i++)
	{
		while(str1[i] != str1[start] && i<l1)
		{
			if(hash1[str1[i]] != 0)
			{	hash2[str1[i]]++;}
			i++;
		}
		if(i == l1) continue;
		end = i;
		int j = start+1;
		while(j <= end)
		{
			if(hash1[str1[j]] ==0 )
			{
				j++;continue;
			}
			else if(hash2[str1[j]] > hash1[str1[j]])
			     {
				hash2[str1[j]]--;
				j++;
				continue;
			     }
			else
			{	
				start = j;
				if(min_len > (end-start+1))
					min_len = end-start+1;
				break;
			}
		}
	}
	for(int i = start ;i<=end;i++)
		cout<<str1[i];
	cout<<endl;
	cout<<"MIN LENGTH : "<<min_len<<endl<<endl;
	return 1;
}
		

