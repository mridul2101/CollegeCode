#include<iostream>

using namespace std;

int powFast(int b, int e) {
    int p = 1;   
    while (e > 0) {
        if(e%2 != 0) {
            p = p*b;  
        } 
        e = e / 2;
        b = b * b;
    }
    return p;
}
int main()
{
	cout<<powFast(2,11)<<endl;
	return 1;
}


