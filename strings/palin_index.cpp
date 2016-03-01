#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string create_string(string s, int j)
{
	string new_str;
	int sz = s.size();
	int i;
	for(i = 0; i < sz; ++i)
	{
		if(i != j)
			new_str += s[i];
	}
	new_str.resize(i-1);
	return new_str;
}

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
		if(sz < 2) {
			cout <<"-1" << endl;
			continue;
		}
		int l = 0;
		int r = sz-1;
		while(l < r)
		{
			cout << a[l] << ' '<< a[r] << endl;
			if(a[l] == a[r])
			{
				l++;
				r--;
			}
			else
				break;
		}
		if(l >= r)
		{
			cout <<"-1" << endl;
			continue;
		}
		int left_s = l;
		int right_s = r;

		bool fault = false;
		l++;
		while(l < r) {
			cout << a[l] << ' '<< a[r] << endl;
			if(a[l] == a[r])
			{
				l++;
				r--;
			}
			else {
				fault = true;
				break;
			}
		}
		if(!fault) cout << left_s << endl;
		else cout << right_s << endl;
	}
	return 0;
}

