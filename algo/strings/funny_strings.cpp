#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string reverse(const string &s)
{
  int sz = s.size();
  string rev;
  for(int i = 0; i < sz; ++i)
    rev += s[sz-i-1];
  rev.resize(sz);
  return rev;
}



int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string str;
		cin >> str;
		string rev_str = reverse(str);
		int sz = rev_str.size();
		bool found=false;

		for(int i = 1; i < sz-1; ++i)
		{
			if( abs(str[i]-str[i-1]) != abs(rev_str[i]-rev_str[i-1]) )
			{
				cout <<"Not Funny" << endl;
				found=true;
				break; 
			}
		}
		if(!found)
			cout <<"Funny" << endl;
	}
	return 0;
}
