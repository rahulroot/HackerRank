#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int anagram(string &a, string &b)
{
  int a_freq[26] = {0};
  int b_freq[26] = {0};

  int len = a.size();
  for(int i = 0; i < len; ++i)
    a_freq[tolower(a[i])-'a']++;

  len = b.size();
  for(int i = 0; i < len; ++i)
	{
			b_freq[tolower(b[i])-'a']++;
	}

  int cnt = 0;
  for(int i = 0; i < 26; ++i)
  {
		cnt += abs(a_freq[i]-b_freq[i]);
  }
	return cnt;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	string a, b;
	cin >> a >> b;
	cout << anagram(a, b) << endl;
	return 0;
}

