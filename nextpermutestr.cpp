#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len = str.length();
        int index = -1;
        for(int i = len-1;i>0;i--){
            if(str[i] > str[i-1]){
                index = i-1;
                break;
            }
        }
        if(index == -1){
            cout<<"no answer"<<endl;
            continue;
        }
        int minindex = -1;        
        for(int i = index+1;i<len;i++){
            if((str[i] > str[index]) ){  
                if(minindex == -1) minindex = i;
                else if((str[i] < str[minindex]))
                    minindex = i;
            }
        }//cout<<minindex<<endl;
        char temp = str[index];
        str[index] = str[minindex];
        str[minindex] = temp;
        string str1 = str.substr(index+1, len);
        sort(str1.begin(), str1.end());

        for(int i =0;i<=index;i++)
            cout<<str[i];
        cout<<str1<<endl;
    }
    return 0;
}
