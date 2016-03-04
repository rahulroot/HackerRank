#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

typedef unsigned long long int ullong;

int count_dig(ullong num)
{
	int c=0;
	while(num)
	{
		num=num/10;
		c++;
	}
	return c;
}

int reverse(int num)
{
	int n=0;
	while(num)
	{
		int r=num%10;
		n=(n*10)+r;
		num=num/10;
	}
	return n;
}

ullong to_int(string &s)
{
  ullong n = 0;
  int sz = s.size();
  for(int i = 0; i < sz; ++i)
  {
    n = (n * 10) + (s[i] - '0');
  }
  return n;
}


int get_sep(ullong n, int &q, int d)
{
	int i = 0;
	int num = 0;
	while(i < d)
	{
		int r = n%10;
		num = num*10+r;
		n=n/10;
		i++;
	}
	q = n;
	return reverse(num);
}

ullong to_dec(string &str, int orig_b)
{
   int len = str.size();
   ullong value = 0;
   for(int i=0; i < len; ++i)
      value += (str[i] - '0') * (long long int)pow(orig_b, len-i-1);
   return value;
}


// d contains the right part of splited string
void split_string(string s, string &l, string &r, int d)
{
	int i = 0;
	int sz = s.size();
	if(sz==1) {
		l = "";
		r = s;
	}
	else
	{
		r = s.substr(sz-d, d);
		l = s.substr(0,d-1);
	}
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int p, q;
	cin >> p >> q;
	bool found = false;
	for(int i = p; i <= q; ++i)
	{
		int in_d = count_dig(i);
		cout <<"Input num : " << i <<' '<<" digit: " << in_d << endl;
		ullong sq = pow(i,2);
		string s = to_string(sq);
		cout <<"sqaure : " << s <<" Digits : "<< s.size() << endl;
		string l, r;
		split_string(s, l, r, in_d);
		cout << " left : " << l <<' ' <<" r_dig: "<< r << endl;
		if(to_dec(l, 10) + to_dec(r, 10) == i)
		{
			cout << i <<' ';
			found = true;
		}
	}
	if(!found)
		cout <<" INVALID RANGE" << endl;
	else
		cout << endl;
	
	return 0;
}
