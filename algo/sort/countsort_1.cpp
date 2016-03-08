#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, num;
	cin >> n;
  vector<int> v(100);
	for(int i = 0; i < n; ++i)
	{
		cin >> num;
		v[num]++;
	}

	vector<int>::iterator it;
	for(it=v.begin(); it!=v.end(); ++it)
		cout << *it <<' ';
	cout << endl;
	return 0;
}
		
	

