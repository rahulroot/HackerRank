#include <bits/stdc++.h>
using namespace std;

typedef long long int ullong;

void kadane(vector<ullong> &vi, int n)
{
	ullong max = -10000;
	ullong cur = 0;
	ullong f_max = 0;
	ullong c_max = -10000;
	for(int i = 0; i < n; ++i)
	{
		/* contigous sub array max sum */
		cur += vi[i];
		if(cur > max)
			max = cur;
		if(cur < 0)
			cur = 0;

		/* non-contigous sub array */
		if( vi[i] > 0)
			f_max += vi[i];
		else if(vi[i] > c_max) 
			c_max = vi[i];
	}
	cout << max <<' ';
	if(f_max > 0 )
		cout << f_max << endl;
	else
		cout << c_max << endl;
}

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ullong> vi(n);
		for(int i = 0; i < n; ++i)
			cin >> vi[i];

		kadane(vi, n);
	}
	return 0;
}
			
