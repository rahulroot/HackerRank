#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
bool anagram(string &a, string &b)
{
  if(a.size() != b.size())
    return false;

  int freq[26] = {0};

  int len = a.size();
  for(int i = 0; i < len; ++i)
    freq[tolower(a[i])-'a']++;

  len = b.size();
  for(int i = 0; i < len; ++i)
    freq[tolower(b[i])-'a']--;

  for(int i = 0; i < 26; ++i)
  {
    if(freq[i] != 0)
      return false;
  }

  return true;
}
int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int cnt = 0;
		string s;
		cin >> s;
    int sz = s.size();
		map<string, int> freq;
  	for(int i = 0; i < sz; ++i)
  	{
    	for(int j = sz-1; j >= i; --j)
			{
      	string sub = s.substr(i, sz-j);
				sort(sub.begin(), sub.end());
				freq[sub]++;
			}
  	}
		map<string, int>::iterator it;	
		for(it=freq.begin(); it!=freq.end(); ++it)
		{	
			if(it->second==2)
				cnt++;
			else if (it->second > 2)
			{
				cnt += ((it->second*(it->second-1))/2);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
