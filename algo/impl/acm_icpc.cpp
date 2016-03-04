#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

typedef unsigned long long int ullong;

int x_compare(string &a, string &b)
{
	int sz = a.size();
	int sub = 0;
	for(int i = 0; i < sz; ++i)
	{
		if( (a[i]=='1') || (b[i] == '1') )
			sub++;
	}
	return sub++;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int n, sub;
	cin >> n >> sub;
	vector<string> v(n);
	for(int i = 0;i < n; ++i)
		cin >> v[i];
	int cnt = 0, max = 0;
	map<int, int> freq;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			int num = x_compare(v[i], v[j]);
			if(num >= max)
			{
				max = num;
				freq[max]++;
			}
		}
	}
	cout << max << endl;
	cout << freq[max] << endl;
	
	return 0;
}

