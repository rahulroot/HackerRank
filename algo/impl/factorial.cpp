#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int fact[101][3000];
void print(int n)
{
  int len = fact[n][0];
  int j;
  for(j=len; j > 0; --j)
		cout << fact[n][j];
	cout << endl;
}
void calc_fact(void)
{
  /* fact(0) = 1 */
  fact[0][0] = 1; /* length of array fact[1] */
  fact[0][1] = 1; /* entry of array fact[1] */
  int i;
  for(i=1; i <= 100; ++i)
  {
    int carry = 0;
    int j=1, tmp=0;
    for(j; (j <= fact[i-1][0]) || (carry) ; ++j)
    {
      int digit = (fact[i-1][j] * i ) + carry;
      fact[i][j] = digit % 10;
      carry = digit / 10;
      tmp++;
      fact[i][0] = tmp;
    }
  }
}
int main()
{
  calc_fact();
  freopen("./sample.txt", "r", stdin);
  int n;
	cin >> n;
  print(n);
  return 0;
}

