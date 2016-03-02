#include <iostream>
#include <string>

#include <map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int sz = s.size();
	map<char, int> freq;
	for(int i = 0; i < sz; ++i)
		freq[s[i]]++;
	bool found = false;
	if(sz%2==0)
	{
		map<char, int>::iterator it;
		for(it=freq.begin(); it!=freq.end(); ++it)
		{
			if( ((it->second)%2) != 0)
			{
				found = true;
				break;
			}
		}
		if(found)
			cout <<"NO"<< endl;
		else
			cout <<"YES"<< endl;
	}
	else
	{
		int cnt = 0;
		map<char, int>::iterator it;
		for(it=freq.begin(); it!=freq.end(); ++it)
		{
			if( ((it->second)%2) != 0)
				cnt++;
		}

		if(cnt==1)
			cout <<"YES" << endl;
		else
			cout <<"NO" << endl;
	}
	return 0;
}
