#include<stdio.h>

#define prn(a) printf("%d",a)
#define print(a,b,c) prn(a), prn(b), prn(c)
#define max(a,b) (a<b)? b:a
#define MAN(x,y) (x)>(y)?(x):(y) 

int main()
{
int x=1, y=2;
print(max(x++,y),x,y);
prn(max(x++,y));
//print(max(x++,y),x,y);
prn(x);
prn(max(x,y));
//print(max(x++,y),x,y);
prn(x);

int p = 2;p = p^p;
printf("\n %d ", p);
prn(p^p);



char ch='A';
while(ch<='F'){
switch(ch){
case'A':case'B':case'C':case'D':ch++;continue;
case'E':case'F':ch++;
}
putchar(ch);
}


int i=10,j=5,k=0;
k= MAN(i++,++j);//k = MAN(i++,++j); => k = i++;
printf("\n\n%d %d %d %d\n",i,j,k);





return 1;
}

