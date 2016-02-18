#include <iostream>
#include <bitset>
#include <limits.h>
#include <vector>
#include <fstream>
#include <assert.h>
const unsigned long int my_max = 2147483648;
using namespace std;
 
int main()
{
  unsigned long int n, s, p, q;
  cin >> n >> s >> p >> q;
  unsigned long int a[3];
  
  unsigned long long my_mul = 0;
  unsigned long my_div = 0;
  
  bitset<my_max> *ba = new bitset<my_max>();
 
  a[0] = s%my_max;
  ba->set(a[0],true);
  for(unsigned int i=1; (i<n); ++i)
  {
    my_mul = (unsigned long long)(a[0]*p+q);
    
    my_div = (unsigned long)(my_mul%my_max);
    a[1] = (unsigned long)(my_div);

    ba->set(a[1],true);
 
    if (a[0] == a[1])
		{
    	break;
		}
    else
    	a[0] = a[1];
 
  }
  
  cout << ba->count() << endl;
  
  delete ba;
  
  return 0;
}
