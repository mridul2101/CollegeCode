//Given an array of strings, sort it so that all anagrams come together.

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	 string name[] = {"john","cat","atc","tac", "bobby", "dear", 
                   "test1", "catherine", "nomi", 
                   "shinta", "martin", "abe", 
                   "may", "zeno", "zack", "angeal", "gabby"};
	
	int len = sizeof(name)/sizeof(name[0]);
	for(int i = 0;i<len;i++)
		sort(name[i].begin(), name[i].end());
	sort(name, name+len);

	for(int i=0;i<len;i++)
		cout<<name[i]<<"  ";
	cout<<endl<<endl;	
}

