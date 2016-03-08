#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define DEBUG 1

using namespace std;

void print(int i)
{
	cout << i <<' ';
}

void partition_array(vector<int> &v, int lb, int ub)
{
	int pivot = v[lb];
	vector<int> left;
	vector<int> right;
	for(int i = 1; i < ub; ++i)
	{
	  if(pivot <= v[i])
			right.push_back(v[i]);
		else if(pivot > v[i])
			left.push_back(v[i]);
	}	
	for_each(left.begin(), left.end(), print);
	cout << pivot <<' ';
	for_each(right.begin(), right.end(), print);
	cout << endl;
}
	


int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	partition_array(v, 0, n);
	return 0;
}
	
