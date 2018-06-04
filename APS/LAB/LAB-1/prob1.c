#include<stdio.h>
#include<string.h>

int main()
{
 int m,n,i;
 scanf("%d%d",&m,&n);
 
 char a[m][11],b[n][11],inter[(m>n)?m:n][10],uni[m+n][10];
 for(i=0;i<m;i++)
  scanf("%s",a[i]);
 
 for(i=0;i<n;i++)
  scanf("%s",b[i]);


int j,k,l;
for(i=0,k=0;i<m;i++)
{ 
  for(j=0;j<n;j++)
  { 
	if(strcmp(a[i],b[j])==0)	
	  strcpy(inter[k++],a[i]);	
  }
}

for(i=0;i<k;i++)
  printf("%s\n",inter[i]);

for(i=0,l=0;i<m;i++)
   strcpy(uni[l++],a[i]);
for(i=0;i<n;i++)
{ 
  for(j=0;j<k;j++)
   if(strcmp(b[i],inter[j])==0)
       break;
   else
	continue;
   if(j==k) 
	strcpy(uni[l++],b[i]);
}
for(i=0;i<l;i++)
  printf("%s\n",uni[i]);
return(0);
}

