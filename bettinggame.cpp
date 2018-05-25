/*
You are involved in a betting game whose rules are as follows :
a) if you win a round, the bet amount will be added to your sum and next bet amount will be $1;
b) if you lose a round, the bet amount will be reduced from your total sum and next bet will be twice the previous.
c) game ends when all the rounds are complete or you dont have sufficient sum.
Initially, you are given with a string of the form “WLWWL” where W indicates a win and L indicates a loss and initial sum. Initial bet amount will be $1.
You need to find the amount at the end of the game.

*/



#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[1024];
	cin>>str;
	int sum,bet;
	sum = bet = 1;

	for(int i=0;i<strlen(str);i++)
	{	
		if(str[i] == 'W')
		{
			sum += bet;
			bet = 1;
		}
		else if(str[i] == 'L')
		     {
			sum -= bet;
			bet *= 2;
			if(sum<1) break;
		     }
	}
	if(sum<1)
	{
		cout<<"\n INSUFFICIENT AMOUNT\n";
	}
	else
	{
		cout<<"\n SUM = "<<sum<<endl;
	}
	return 1;
}


