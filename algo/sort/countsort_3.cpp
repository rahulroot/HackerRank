#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, num;
	string str;
	cin >> n;
  vector<int> v(100);
	for(int i = 0; i < n; ++i)
	{
		cin >> num >> str;
		v[num]++;
	}

	int prev = v[0];
	cout << prev <<' ';
	for(int i = 1; i < 100 ; ++i)
	{
		prev += v[i];
		cout << prev <<' ';
	}
	cout << endl;
	return 0;
}
		
	

