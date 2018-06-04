#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  int t;
  cin>>t;
  long long int a,b,c,n;
  while(t--)
  {
	long long int no=1,f=1,i=2,median=0,sum=1;
	cin>>a>>b>>c>>n;
	
  	vector<int> max_heap;
	vector<int> min_heap;

	make_heap(max_heap.begin(),max_heap.end());
	make_heap(min_heap.begin(),min_heap.end());
	max_heap.push_back(1);
	push_heap (max_heap.begin(),max_heap.end());
		
	median=1;
	while(i<=n)
	{

	   f=((a*median)+(b*i)+c) % 1000000007;
	   sum+=f;
	   
	   
	   no++;
	   if(max_heap.front()>f)
	   {
		   max_heap.push_back(f);
		   push_heap (max_heap.begin(),max_heap.end());
	   }
	   else if(max_heap.front()<=f)
	   {
		   min_heap.push_back((-1)*f);
		   push_heap (min_heap.begin(),min_heap.end());
	   }
	   
	   if((max_heap.size()-min_heap.size())==2)
	   {
		min_heap.push_back((-1)*max_heap.front());
		push_heap (min_heap.begin(),min_heap.end());

		
		pop_heap(max_heap.begin(),max_heap.end());	
		max_heap.pop_back();	
	   }
	   else if((max_heap.size()-min_heap.size())==-2)
		{
			max_heap.push_back((-1)*min_heap.front());
			push_heap (max_heap.begin(),max_heap.end());

				
			pop_heap(min_heap.begin(),min_heap.end());
			min_heap.pop_back();	
		}

		if(min_heap.size()>max_heap.size())
			median=((-1)*min_heap.front());
		else
			median=max_heap.front();
	   i++;
	}
	cout<<sum<<endl;
	
   }
return(0);
}		
	






