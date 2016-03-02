#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <numeric>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++)
	{
    int n;
    int c;
    int m;
    cin >> n >> c >> m;
		vector<int> v;

		int choc = 0, wra = 0;
		wra = choc = n/c;
		v.push_back(choc);
		int choc_1 = 0;
		while(wra >= m)
		{
			choc_1 = wra/m;
			v.push_back(choc_1);
			int rem = wra%m;
			wra = choc_1 + rem;
		}
		
		cout << accumulate(v.begin(), v.end(), 0) << endl;
  }
  return 0;
}
