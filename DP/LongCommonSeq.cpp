/*
	LONGEST COMMON SEQUENCE AMONG TWO STRING (Recursive Approach)
*/


#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int **hashmap2D;
int max(int a, int b)
{
	if(a > b) return a;
	else	return b;
}

int findSeq(char *A, char *B, int m, int n){
	
	cout<<"\n In FIND SEQ FUNCTION  "<<m<<"  "<<n;


	if(m == 0 || n == 0){
		return 0;	
	}
	else if(A[m-1] == B[n-1]){
		//if(hashmap2D[m-1][n-1] == -1)
		{
			hashmap2D[m-1][n-1] = findSeq(A,B,m-1,n-1); 		
		}
		return (1 + hashmap2D[m-1][n-1]);
	}
	else{
		return (max(findSeq(A,B,m-1,n), findSeq(A,B,m,n-1)));
	}
}



int main()
{
	char A[] = "AGGTABABHJB";
	char B[] = "GXTXAXBAKJJBJHV";

	hashmap2D = (int**) malloc(strlen(A) * sizeof(int*));
	for(int i=0;i<strlen(A);i++)
	{
		hashmap2D[i] = (int*) malloc(strlen(B) * sizeof(int));
		for(int j=0;j<strlen(B);j++) hashmap2D[i][j] = -1;
	}


	int value = findSeq(A, B, strlen(A),strlen(B));
	cout<<"\n Max Seq = "<<value<<endl;

	return 1;
}

