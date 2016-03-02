#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void enc_lower(char &c, int k)
{
	int i = 0;
	while(i<k)
	{
		if(c=='z')
			c = 'a';
		else
			c++;
		i++;
	}
}

void enc_upper(char &c, int k)
{
	int i = 0;
	while(i<k)
	{
		if(c=='Z')
			c = 'A';
		else
			c++;
		i++;
	}
}

int main()
{
	freopen("./sample.txt", "r", stdin);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
	
	for(int i =0; i < n; ++i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
		  enc_lower(s[i],k);
		}
		else if( s[i] >= 'A' && s[i] <= 'Z')
		{
			enc_upper(s[i],k);	
		}
	}
	cout << s << endl;
  return 0;
}

