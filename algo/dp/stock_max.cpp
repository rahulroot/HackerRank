#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> &price, int n,int st, int &end);

bool is_dec(vector<int> &price, int n)
{
	bool dec = true;
	for(int i = 1 ; i < n; ++i)
		if(price[i] > price[i-1])
			dec = false;
	return dec;
}

void cal_profit(vector<int> &price, int n)
{
	int m = 0;
	long long int profit = 0;
	int st = 0, end = 0;
	if(is_dec(price, n))
	{
		cout << "0" << endl;
		return;
	}
	while( end != n-1)
	{
		m = find_max(price, n, st, end);
		long long int buy = 0;
		int i = 0, cnt=0;
		for(i = st; i < end; ++i)
		{
			buy += price[i];
			cnt++;
		}
		unsigned long long sell = (unsigned long long)cnt*price[i];
		profit += (sell-buy);
		st = end+1;
	}

	cout << profit << endl;
}

int find_max(vector<int> &price, int n,int st, int &end)
{
	int m = 0;
	for(int i = st;i < n; ++i)
	{
		if( price[i] > m)
		{
			m = price[i];
			end = i;
		}
	}
	return m;
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
		vector<int> price(n);
		for(int i = 0; i < n; ++i)
			cin >> price[i];	
		cal_profit(price, n);
	}
	return 0;
}
