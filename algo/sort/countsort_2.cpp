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

	for(int i = 0; i < 100 ; ++i)
	{
		int x = v[i];
		while(x--)
			cout << i <<' ';
	}
	cout << endl;
	return 0;
}
		
	

