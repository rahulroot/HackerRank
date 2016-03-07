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

void reverse_string(string &s, int st, int en)
{
  if( st <= en )
  {
    char ch = s[st];
    s[st] = s[en];
    s[en] = ch;
    reverse_string(s, ++st, --en);
  }
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
		string::reverse_iterator rit;
		rit = s.rbegin();
		while(i < d)
		{
			r += *rit;
			i++; ++rit;
		}
		r.resize(d);
		reverse_string(r,0,r.size()-1);
		l = s;
		l.resize(sz-d);
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
		ullong sq = pow(i,2);
		string s = to_string(sq);
		string l, r;
		split_string(s, l, r, in_d);
		if(to_dec(l, 10) + to_dec(r, 10) == i)
		{
			cout << i <<' ';
			found = true;
		}
	}
	if(!found)
		cout <<"INVALID RANGE" << endl;
	else
		cout << endl;
	
	return 0;
}
