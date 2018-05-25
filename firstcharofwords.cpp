/*
Given a string containing words separated by arbitrary number of spaces. Write a function that returns a string consisting of the first letter of each word. (Note: there may be any number of spaces at the starting of the given string, at the end of the given string or in between words of the string.)
Example:
Input: ” this is a test case ”
Output: tiatc
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string str;
	getline(cin,str);

	int len = str.length();
	char *s = new char(len);
	str.copy(s, len);

	char *temp;
	string output = "";

	temp = strtok(s," ");
	while(temp != NULL)
	{
		output += temp[0];

		temp = strtok(NULL, " ");
	}

	cout<<output<<endl;
	return 1;
}


