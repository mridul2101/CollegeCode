/*


Your task is, given a string S, check whether it is a palindrome or not. Easy.. isn't it ?

Wait, here is a twist if its not a palindrome you have to split it in to palindromes in such a way that their concatenation gives S. Still easy ?

Now to make this task really good, you have to split in such a way that minimum number of palindromes are formed. In other words, you have to find the minimum number of palindromic pieces, whose concatenation is S

Constraints:

1 <= Length of String (S)<= 5600
Time Limit : 1s

Input:
Single Line contains a String S which will only contain [ 'A' - 'Z' ].

Output:
Print the minimum number of palindromes in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Sample Case 1:
Input:
REDIVIDER
Output:
1\n
Explanation:
No need to Split, as its already a palindrome.

Sample Case 2:

Input:
APSISCOOL
Output:
6\n
Explanation:
Following are the pieces, A + P + SIS + C + OO + L --> APSISCOOL  ( total 6 pieces).

*/



#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[5602];
	cin>>(s+1);
	int l=strlen(s+1);

	int dyn_array[l+1];
	char s1[5602];
	
	for(int i=1;i<=l;i++)
		s1[i]=s[l+1-i];
	dyn_array[0]=0;dyn_array[1]=1;
	
	for(int i=1;i<=l;i++)
	{
		dyn_array[i]=dyn_array[i-1]+1;
		for(int j=0;j<i;j++)
		{
			int flag=0;
			int p,q;
			p=j+1;q=i;
			
			if(memcmp(s+p,s1+l+1-q,q-p+1)==0)
				flag=1;
			if(dyn_array[j]+1<dyn_array[i] && flag==1)
				dyn_array[i]=dyn_array[j]+1;
		}
	}

	cout<<dyn_array[l]<<endl;
	return(0);
}




