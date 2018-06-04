/*Given a grid of lights(R X C), our goal is to turn on all the lights. 1 = on, 0 = off.Flipping a blub means, changing its state ( from on to off, or off to on ). If we flip a bulb(i,j), all the bulbs in a matrix consisting of rows [0..i] and columns [0..j] also get flipped.

eg:
0 1 1 0
0 0 * 1
0 1 0 1
1 1 0 1

lets say bulb (1,2), marked as * is actually 0 and if you flip it the grid becomes

1 0 0 0
1 1 1 1
0 1 0 1
1 1 0 1

(i.e., all (0,0) to (i,j) flipped ).

Objective : You have to turn on all lights using minimum flips.

Constraints:
1 <= R,C <= 100
Time limit : 1s

Input :
First line contains R(1<=R<=100) and C(1<=C<=100)
following line contains the matrix(R X C) input

Output :
Print the answer in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Examples :
Input :
2 3
1 1 1
1 0 1
Output :
4\n

Input :
3 3
1 1 1
0 0 0
0 0 0
Output:
2\n
*/

#include<iostream>
using namespace std;

void flip(int**,int,int);

int main()
{
	int r,c,count=0;
	cin>>r>>c;
	int **a=NULL;
	a=new int *[r];
	for(int i=0;i<r;i++)
	{
	    a[i]=new int[c];
  	    for(int j=0;j<c;j++)
		cin>>a[i][j];
	}

	for(int i=r-1;i>=0;i--)
	{
		for(int j=c-1;j>=0;j--)
		{
			if(a[i][j]==0)
			{  
			   flip(a,i+1,j+1);
			   count++;
			}
		}
	}

	cout<<count<<endl;
return(0);
}

void flip(int** a,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
		    if(a[i][j]==1)
		 	a[i][j]=0;
		    else
		 	a[i][j]=1;			
		}
	}
}
			











