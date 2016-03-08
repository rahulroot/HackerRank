#include <bits/stdc++.h>
using namespace std;

struct ds 
{
	int in;
	pair<int, string> mypair;
};

bool compare(const struct ds &a, const struct ds &b)
{
	return a.mypair.first < b.mypair.first;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, num;
	string str;
	cin >> n;
  vector<ds> v;
	for(int i = 0; i < n; ++i)
	{
		cin >> num >> str;
		struct ds tmp = {i, make_pair(num, str) };
		v.push_back(tmp);
	}

	stable_sort(v.begin(), v.end(), compare);

	vector<ds>::iterator it;
	for(it=v.begin(); it!=v.end(); ++it)
	{
		if(it->in < n/2)
			cout << "-" <<' ';
		else
			cout << it->mypair.second <<' ';
	}
	

	cout << endl;
	return 0;
}
		
	

