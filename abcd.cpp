#include<stdio.h>
#include<string.h>

char S[2][100005];

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
   int i,j,N,flag[4]={0};
   scanf("%d",&N);
   scanf("%s",S);
   
   
   for(i=0;i<2*N;i+=2)
   {   
       flag[0] = flag[1] = flag[2] = flag[3] = 1;
       flag[S[0][i] - 'A'] = flag[S[0][i+1] - 'A'] = 0;
       
       for(j=0; j<=3; j++)
       {
           if(flag[j]) { flag[j] = 0; S[1][i] = j+65; break; }
       }
       
       for(j=0; j<=3; j++)
       {
           if(flag[j]) { flag[j] = 0; S[1][i+1] = j+65; break; }
       }
       
       if(S[1][i] == S[1][i-1]){
        swap(&S[1][i], &S[1][i+1]);
        /*char ch=S[1][i];
        S[1][i]=S[1][i+1];
        S[1][i+1]=ch;*/
        }
   }
   
   printf("%s",S[1]);
  return 0;      
}
