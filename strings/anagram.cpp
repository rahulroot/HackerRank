#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		string a;
		cin >> a;
		int sz = a.size();
		if(sz%2!=0)
		{
			cout <<"-1" << endl;
			continue;
		}
		int cnt = sz/2;
		string f = a.substr(0, cnt);
		string s = a.substr( ((sz-1)/2)+1, cnt);
		cout << f <<' '<< s << endl;
		int a_f[26] = {0};
		int b_f[26] = {0};
		for(int i = 0; i < cnt; ++i)
			a_f[f[i]-'a']++;
		for(int i = 0; i < cnt; ++i)
			b_f[s[i]-'a']++;

		int c = 0;
		for(int i = 0;i < cnt; ++i)
			c += abs(a_f[i] - b_f[i]);

		cout << c << endl;
	}
	return 0;
}
