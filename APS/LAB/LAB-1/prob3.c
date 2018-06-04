#include<stdio.h>

int main()
{
  int t,i,j,p;
  scanf("%d",&t);
  char hex[t][100000];
  for(i=0;i<t;i++)
    scanf("%s",hex[i]);

  for(i=0;i<t;i++)
  {int flag=0;
     for(j=0;hex[i][j]!='\0';j++)
     {int k=0;
	p=(int)hex[i][j];

	if(p>=65)
	   p-=55;
	else
	   p-=48;
	for(k=3;k>=0;k--)
	{if(((p>>k)&1)==1)
	  flag=1;
	if(flag==1)
	printf("%d",((p>>k)&1));
    }}printf("\n");
  }
return(0);
}

