#include <bits/stdc++.h>
using namespace std;

#define MAXDIGITS 70000    /* maximum length bignum */

#define PLUS    1   /* positive sign bit */
#define MINUS   -1    /* negative sign bit */

int table[25][MAXDIGITS] = {0};


typedef struct {
  short digits[MAXDIGITS];         /* represent the number */
  int signbit;      /* 1 if positive, -1 if negative */
  int lastdigit;      /* index of high-order digit */
} bignum;

void add_bignum(bignum &a, bignum &b, bignum &c);
int compare_bignum(bignum &a, bignum &b);
void digit_shift(bignum &n, int d);   /* multiply n by 10^d */
void multiply_bignum(bignum &a, bignum &b, bignum &c);
void zero_justify(bignum &n);
void to_bignum(int s, bignum &n);

void initialize_bignum(bignum &n)
{
  memset(&n, 0, sizeof(bignum));
}

void digit_shift(bignum &n, int d)    /* multiply n by 10^d */
{
  int i;        /* counter */

  if ((n.lastdigit == 0) && (n.digits[0] == 0))
    return;

  for (i=n.lastdigit; i>=0; i--)
    n.digits[i+d] = n.digits[i];

  for (i=0; i<d; i++)
    n.digits[i] = 0;

  n.lastdigit = n.lastdigit + d;
}




void to_bignum(int s, bignum &n)
{
  int i;        /* counter */
  int t;       /* int to work with */

 // for (i=0; i<MAXDIGITS; i++)
  //  n.digits[i] = 0;

  n.lastdigit = -1;

  t = llabs(s);

  while (t > 0) {
    n.lastdigit ++;
    int rem = ( t % 10);
    n.digits[n.lastdigit] = rem;
    t = t / 10;
  }

  if (s == 0) n.lastdigit = 0;
}

void add_bignum(bignum &a, bignum &b, bignum &c)
{
  int carry;      /* carry digit */
  int i;        /* counter */

  initialize_bignum(c);

  c.lastdigit = max(a.lastdigit,b.lastdigit)+1;
  carry = 0;

  for (i=0; i<=(c.lastdigit); i++) {
    int rem = (carry+ a.digits[i]+ b.digits[i])%10;
    c.digits[i] = rem;
    carry = (carry + a.digits[i] + b.digits[i]) / 10;
  }
  zero_justify(c);
}

void zero_justify(bignum &n)
{
  while ((n.lastdigit > 0) && (n.digits[ n.lastdigit ] == 0))
    n.lastdigit --;

  if ( (n.lastdigit == 0) && (n.digits[0] == 0) )
    n.signbit = PLUS; /* hack to avoid -0 */
}

void multiply_bignum(bignum &a, bignum &b, bignum &c)
{
  bignum row;     /* represent shifted row */
  bignum tmp;     /* placeholder bignum */
  int i,j;      /* counters */

  initialize_bignum(c);

  row = a;

  for (i=0; i<=b.lastdigit; i++)
  {
    for (j=1; j<=b.digits[i]; j++)
    {
      add_bignum(c,row,tmp);
      c = tmp;
    }
    digit_shift(row,1);
  }
  c.signbit = a.signbit * b.signbit;
  zero_justify(c);
}

/* assign the bignum to table at index i */
void to_table(int in, bignum final)
{
	table[in][0] = final.lastdigit+1;
	int j;
	for(int i = final.lastdigit, j = 1; i>=0; --i, ++j)
		table[in][j] = final.digits[i];
}

/* assign the table index to bignum for further processing */
void to_big(int in, bignum &tmp)
{
	tmp.signbit = PLUS;
	tmp.lastdigit = table[in][0];
	int j;
	for(int i = tmp.lastdigit, j = 0; i>0; --i,++j)
		tmp.digits[j] = table[in][i];
}

void copy_bignum(bignum &src, bignum &dest)
{
	dest.lastdigit = src.lastdigit;
	for(int i = 0; i <= dest.lastdigit; ++i)
		dest.digits[i] = src.digits[i];
}

void print_fab(int in)
{
	for (int i=1; i <= table[in][0]; ++i)
    cout << table[in][i];
  cout << endl;
}

void print_bignum(bignum n)
{
  int i;
  if (n.signbit == MINUS)
    cout <<"- ";
  for (i=n.lastdigit; i>=0; i--)
    cout << n.digits[i];
  cout << endl;
}

void cal_fab(int a, int b, int n)
{
	table[1][0] = 1; /* contains length of this number */
	table[1][1] = a; /* contains the integer itself */

	table[2][0] = 1;
	table[2][1] = b;

	bignum big_c = {0};
	bignum big_a = {0};
	bignum big_b = {0};
	bignum tmp, final;

  to_bignum(a, big_a);
	to_bignum(b, big_b);	

	for(int i = 3; i <= n; ++i)
	{
		cout <<"Ith iteration. " << i << endl;
		multiply_bignum(big_b, big_b, big_c);
		//cout <<"After Multiply. "; print_bignum(big_c);
		add_bignum(big_a, big_c, final);
		//cout <<"After addition. "; print_bignum(final);
		//to_table(i, final);
		//cout <<"To table from bignum. "; print_fab(i);
		copy_bignum(big_b, big_a);
  	initialize_bignum(big_b);
		copy_bignum(final, big_b);
  	initialize_bignum(big_c);
		//to_big(i-1, big_a);
		//cout <<"From table to bignum. "; print_bignum(big_a);
	}
	print_bignum(final);
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int a, b, n;
	cin >> a >> b >> n;
	cal_fab(a, b, n);
	
	return 0;
}
