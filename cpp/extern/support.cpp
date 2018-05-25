#include <iostream>
using namespace std; 

extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
