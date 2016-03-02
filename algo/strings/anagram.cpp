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

		sort(s.begin(), s.end());

		int c = 0;
		for(int i = 0;i < cnt; ++i)
		{
			if(!binary_search(s.begin(), s.end(), f[i]))
				c++;
			else
			{
				size_t found = s.find(f[i]);
				s.erase(found,1);
			}
		}

		cout << c << endl;
	}
	return 0;
}
