#include <bits/stdc++.h>
using namespace std;
int dp[51][251] = {0};
int coins[51] = {0};
void print_dp(int n, int m);

void dp_table(int n, int m)
{
	for(int i = 1; i <= m; ++i)
		dp[i][0] = 1;

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			if( coins[i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
		}
	}
	cout << dp[m][n] << endl;
}

void print_dp(int amount, int cs)
{
  cout << setw(4) <<' ';
  for(int i = 0; i <= amount; ++i)
    cout << setw(4) << i;
  cout << endl;
  cout << setw(4) <<' ';
  for(int j = 0; j <= amount; ++j)
    cout << setw(4) << dp[0][j];
  cout << endl;
  for(int i = 1; i <= cs; ++i)
  {
    cout << setw(4) << coins[i];
    for(int j = 0; j <= amount; ++j)
    {
      cout << setw(4) << dp[i][j] ; //"("<<i+1<<','<<j<<")";
    }
    cout << endl;
  }

	cout <<"Printing only DP." << endl;
	for(int i = 0; i <= cs; ++i)
	{
		for(int j = 0; j <= amount; ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << dp[cs][amount] << endl;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m; ++i)
		cin >> coins[i];

	dp_table(n, m);
	return 0;
}
