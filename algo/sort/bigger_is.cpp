#include <bits/stdc++.h>
using namespace std;

bool compare(string &a, string &b)
{
	return a < b;
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		string tmp = s;
		if(s.size()==1)
		{
			cout << "no answer" << endl;
			continue;
		}
		
		do
    {
			if(s != tmp)
				break;
    } while(next_permutation(s.begin(), s.end()));
		if(tmp == s)
		{
			cout << "no answer" << endl;
			continue;
		}
		else
		{
			bool is_big = compare(tmp, s);
			if(is_big)
				cout << s << endl;
			else
				cout << "no answer" << endl;
		}
	}
	return 0;
}
