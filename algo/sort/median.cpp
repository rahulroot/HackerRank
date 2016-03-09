#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << v[v.size()/2] << endl;
	return 0;
}
