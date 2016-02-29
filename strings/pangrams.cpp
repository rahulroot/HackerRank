#include <iostream>
#include <map>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	map<char, int> freq;
	for(int i = 0; i < 26; ++i)
		freq['a'+i]=0;
	string s;
	getline(cin,s);
	int len = s.size();
	for(int i = 0; i < len; ++i)
		freq[tolower(s[i])]++;
	map<char, int>::iterator it;
	bool found = false;
	for(it=freq.begin(); it!=freq.end(); ++it)
	{
		if(it->second == 0)
		{
			cout << "not pangram" << endl;
			found = true;
			break;
		}
	}
	if(!found)
		cout << "pangram" << endl;
	return 0;
}
