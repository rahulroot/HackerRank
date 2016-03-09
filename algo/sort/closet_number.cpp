#include <bits/stdc++.h>
using namespace std;

void print(const pair<int,int> &a)
{
	cout << a.first <<' ' << a.second <<' ';
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if( a.first < b.first)
		return true;
	else if( a.first == b.first)
	{
		if( a.second < b.second)
			return true;
		else
			return false;
	}
	return false;
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	pair<int, int> mypair;
	vector<pair<int, int> > final;

	int min = abs(v[n-1]);
	for(int i = 1; i < n; ++i)
	{
		int tmp = abs(v[i]-v[i-1]); 
		if(tmp <= min)
		{
			if( min != tmp)
			{
				while(!final.empty())
					final.pop_back();
			}
			min = tmp;
			final.push_back(make_pair(v[i-1], v[i]));
		}
	}
	sort(final.begin(), final.end(), compare);

	for_each(final.begin(), final.end(), print);
	cout << endl;

	
	return 0;
}

