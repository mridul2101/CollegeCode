/*


Length of the longest substring without repeating characters
December 2, 2011

Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7. 
*/

#include<iostream>
#include<string.h>
using namespace std;

int longestsubstr(char A[], int hash[], int n)
{
	int start, end, max;
	hash[A[0]] = 0;
	start = end = 0;
	max = 1;
	
	for(int i = 1 ;i < n; i++)
	{
		if(hash[(int)A[i]] == -1 || (hash[(int)A[i]] < start) )
		{
			end = i;
			hash[(int)A[i]] = i;
		}
		else
		{
			start = hash[(int)A[i]] + 1;
			end = i;
			hash[(int)A[i]] = i;
		}
		if(max < (end - start + 1))
		{
			max = end - start + 1;
			for(int i = start ;i<= end;i++) cout<<A[i];cout<<endl;
		}
	}

	
	cout<<endl;
	return max;
}

int main()
{
	string str;
	cin>>str;
	char A[str.length()];
	strcpy(A, str.c_str());

	int hash[256] = {-1};
	int max ;
	max = longestsubstr(A, hash, strlen(A));
	cout<<"MAXIMUM : "<<max<<endl;
	return 1;
}

