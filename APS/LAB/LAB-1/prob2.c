#include<stdio.h>

int main()
{
int t,i,p;
scanf("%d",&t);
long int a[t],b[t];
for(i=0;i<t;i++)
{ scanf("%ld",&a[i]);
  scanf("%ld",&b[i]);
}


for(i=0;i<t;i++)
{
  p=a[i] ^ b[i];
 int n=0;
  while(p!=0)
 {
   p=p & (p-1);
   n++;
 }
 
printf("%d\n",n);
}
return(0);
}
