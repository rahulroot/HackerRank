#include <bits/stdc++.h>
using namespace std;

void print(int i )
{
	cout << i <<' ';
}

void right_shift(vector<int> &v, int n, int k)
{
	while(k--)
	{
		int tmp = v[n-1];
		for(int i = 0; i < n-1; ++i)
			v[n-1-i] = v[n-2-i];
		v[0] = tmp;
		cout << k <<"th itr: ";
		for_each(v.begin(), v.end(), print); cout << endl;
	}
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, k ,q;
	cin >> n >> k >> q;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	while(q--)
	{
		int id;
		cin >> id;
		if( id-k > 0)
			cout << v[id-k] << endl;
		else
			cout << v[id-k+n] << endl;
	}

	return 0;
}

	
