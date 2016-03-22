#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> rank(n);
	for(int i = 0;i < n; ++i)
		cin >> rank[i];

	vector<int> candies(n,1);

	for(int i = 1; i < n; ++i)
		if( rank[i] > rank[i-1])
			candies[i] = candies[i-1]+1;

	for(int i = n-1; i>=0; --i)
		if( rank[i-1] > rank[i] && candies[i] >= candies[i-1])
			candies[i-1] = candies[i]+1;

	unsigned long int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += candies[i];

	cout << sum << endl;
 	return 0;
}
