#include<iostream>
#include<string.h>
using namespace std;

void correctWord(string str, int len, int start){
    if(start == len)
        return;
    for(int i=start;i<=len;i++)
        cout<<str.substr(start, i)<<endl;
    correctWord(str, len, start+1);
}

int main(){
    string str;
    cin>>str;

    int len = str.length();
    correctWord(str, len, 0);
    return 0;
}
