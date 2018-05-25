//TRIES INSERT AND SEARCH

#include<iostream>
#include<string.h>
using namespace std;

class TrieNode
{
	public: char value;
	 	int end_flag;
		TrieNode *next[26];
	TrieNode()
	{
		value = '0';
		end_flag = 0;
		for(int i=0;i<26;i++)
			next[i] = NULL;
	}
};

class Tries
{
	TrieNode *root;
	public:
	Tries()
	{
		root = new TrieNode();
	}
	void triesInsert(char str[])
	{
		TrieNode *temp;
		temp = root;
		for(int i=0;i<strlen(str);i++)
		{
			if(temp->next[((int)str[i])-65] == NULL)
			{
				TrieNode *tempchar;
				tempchar = new TrieNode();
				tempchar->value = str[i];
				temp->next[((int)str[i])-65] = tempchar;
				temp = tempchar;
			}
			else
			{
				temp = temp->next[((int)str[i])-65];
			}
		}
		temp->end_flag = 1;
		return;
	}
	
	int triesSearch(char str[])
	{
		if(strlen(str) == 0) return 0;
		TrieNode *temp;
		temp = root->next[((int)str[0])-65];
		
		for(int i=1;i<strlen(str);i++)
		{
			if(temp == NULL) 
				return 0;
			else
			{
				temp = temp->next[((int)str[i])-65];
			}
			
		}
		if(temp != NULL)
		if(temp->end_flag == 1)
			return 1;
		return 0;		
	}

};

int main()
{
	Tries tr;
	char str[]="apple";
	tr.triesInsert("apple");
	tr.triesInsert("app");
	tr.triesInsert("appie");
	tr.triesInsert("boy");
	tr.triesInsert("cat");
	tr.triesInsert("ate");


	if(tr.triesSearch("apple") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	if(tr.triesSearch("app") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	if(tr.triesSearch("appie") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	if(tr.triesSearch("boy") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	if(tr.triesSearch("cap") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	if(tr.triesSearch("ated") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	if(tr.triesSearch("n") == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 1;
}













		













