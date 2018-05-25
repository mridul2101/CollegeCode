
//Reverse Words
//Input : Heys I am Mridul
// I Step : syeH I ma ludirM
//II Step : Mridul am I Heys


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

string ReverseWords(string temp)
{
	char str[temp.length()];
	strcpy(str,temp.c_str());
	
	string t;
	temp = "";
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i] == ' ')
		{
			t = string(t.rbegin(), t.rend());
			temp += t;
			temp += " ";
			t = "";
			continue;
		}		
		t += str[i];
	}
	if(t != "")
	{
		t = string(t.rbegin(), t.rend());
		temp += t;
	}
	
	cout<<"I : "<<temp<<endl;
	return temp;
}


int main()
{
	string temp;	
	getline(cin, temp);

	temp = ReverseWords(temp);
	temp = string(temp.rbegin(), temp.rend());

	cout<<"II : "<<temp<<endl;
		

	return (0);
}
