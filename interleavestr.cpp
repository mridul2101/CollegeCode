/*
Given two strings str1 and str2, write a function that prints all interleavings of the given two strings. You may assume that all characters in both strings are different 
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	char str[strlen(str1.c_str()) + strlen(str2.c_str()) + 1];
	strcpy(str, str1.c_str());
	strcat(str, str2.c_str());

	sort(str, str + strlen(str));


	do{
		cout<<str<<endl;
	}while(next_permutation(str, str + strlen(str)));
	return 1;
}

	

