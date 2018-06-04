/*A small child (very cute) went for shopping crackers in a mall for Diwali. All the crackers were kept for a display in a queue. Child was very intelligent he can guess the exact height of the cracker by seeing it. He was also stratergic, he will only take a cracker of more or equall height than what he already purchase. He wants to buy maximum number of crackers by making a single pass of a queue.

Can you guys please help that child to purchase the crackers in such a way that he gets maximum number of crackers and that too in the non-decreasing order of height.

Input:

First line contains N(total numbers of crackers). Second line contains the height of N crackers.(Height can be negative also)

Constraints:
1 <= N <= 3000
-10^5 <= Height <= 10^5
Time Limit : 1s

Output:
Maximum numbers of crackers.
Print the answer in a single line  followed by a '\n' ( just print a new line  no need to display '\n' )

Sample Case 1:

Input:
10
6 3 4 8 10 5 7 1 9 2
Output:
5\n

Explaination:
Child will buy crackers of height 3,4,5,7,9

Sample Case 2:

Input:
10
-6 3 -4 8 -4 5 -1 1 9 2
Output:
6\n

Explaination:
Child will buy crackers of height -6,-4,-4,-1,1,2
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ht[n],count[n],max=0;
	for(int i=0;i<n;i++)
		count[i]=1;
	for(int i=0;i<n;i++)
		cin>>ht[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(ht[i]>=ht[j] && count[i]<=count[j])
				count[i]=count[j]+1;
		}
		if(max<=count[i])
			max=count[i];
		
	}
	cout<<max<<endl;
	return(0);
}
		


