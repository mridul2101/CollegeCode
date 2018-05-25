/*


Dynamic Programming | Set 12 (Longest Palindromic Subsequence)

Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

The naive solution for this problem is to generate all subsequences of the given sequence and find the longest palindromic subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.
*/

#include<iostream>
#include<string.h>
using namespace std;

bool is_palid(char str[], int i, int j)
{
	while(i <= j)
	{
		if(str[i] != str[j])	
			return false;
		i++;
		j--;
	}
	return true;

}
int palinmaxsubstr(char str[], int i, int j)
{
	if(i == j) return 1;

	if((str[i] == str[j] ) && (i+1 == j))
		return 2;

	if(is_palid(str, i, j))
		return (palinmaxsubstr(str,i+1, j-1) + 2);
	
	return(max((palinmaxsubstr(str,i, j-1) ), (palinmaxsubstr(str,i+1, j) )));
}
class value
{
	public :
	int m;
	char string[1024];
 
		value(int a, char s[])
		{
			m = a;
			strcpy(string,s);
		}
};

value* substrpalinmaxsubstr(char str[], int i, int j)
{
	if(i == j)
	{
		char temp[1024];
		strncpy(temp,str + i , 1); 
		 return new value(1, temp);
	}

	if((str[i] == str[j] ) && (i+1 == j))
	{
		char temp[1024];
		strncpy(temp,str + i , 2); 		
		return new value(2, temp);
	}

	if(is_palid(str, i, j))
	{
		char temp[1024];
		strncpy(temp, str + i, j-i+1);
		return new value((palinmaxsubstr(str,i+1, j-1) + 2),temp);
	}
	value *v1, *v2;
	v1 = substrpalinmaxsubstr(str,i, j-1);
	v2 = substrpalinmaxsubstr(str,i+1, j) ;

	if((v1->m) > (v2->m))
		return v1;
	else
		return v2;
}

int main()
{
	char str[1024];
	cin >> str;
	
	cout<<palinmaxsubstr(str, 0, strlen(str))<<endl;
	value *v = substrpalinmaxsubstr(str, 0, strlen(str));

	cout<<v->m<<"  "<<v->string<<endl;

	return 1;
}







