#include<iostream>
#include<string.h>
using namespace std;

void swap(char *str, int p, int i){
	char temp = str[p];
	str[p] = str[i];
	str[i] = temp;
}

void allpermute(char *str, int n, int p){
	if(p == (n-1))
		cout<<str<<endl;
	else{
		for(int i=p;i<n;i++)
		{
			swap(str, p, i);
			allpermute(str, n, p+1);
			swap(str, p, i);
		}			
	}
}

int main(){
	char str[] = "ABCD";
	allpermute(str, strlen(str), 0);
	return 0;
}

