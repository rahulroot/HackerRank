#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("./sample.txt" ,"r", stdin);
	int t;
	cin >> t;
	set<char> freq;
	vector<string> vs;
	while(t--)
	{
		string a;
		cin >> a;
		vs.push_back(a);
	}
	
	vector<string>::iterator it;
	bool first = false;
	set<char> vss;
	set<char>::iterator sit;
	for(it=vs.begin(); it!=vs.end(); ++it)
	{
		if(!first)
		{
			string s  = *it;
			int sz = s.size();
			for(int i = 0;i < sz; ++i)
				freq.insert(s[i]);
			first = true;
		}
		else
		{
			vss.clear();
			set<char> s_freq;
			string s  = *it;
			int sz = s.size();
			for(int i = 0;i < sz; ++i)
				s_freq.insert(s[i]);
			set_intersection(freq.begin(), freq.end(), s_freq.begin(), s_freq.end(), insert_iterator<set<char> >( vss, vss.begin()));
			freq.clear();
			s_freq.clear();
			freq=vss;
		}
	}
  cout << (int)vss.size() << endl;
	
	return 0;
}
