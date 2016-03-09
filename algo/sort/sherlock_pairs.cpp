#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int n, num;
		cin >> n;
		vector<int> v(1000001);
		for(int i = 0;i < n; ++i)
		{
			cin >> num;
			v[num]++;
		}
		unsigned long long count = 0;
		for(int i = 0;i < 1000001; ++i)
		{
			if(v[i] > 1)
			{
			  unsigned long long m = (unsigned long long)v[i]*(v[i]-1);	
				count = (long long)count + m;
			}
		}
		cout << count << endl;
	}
	return 0;
}
