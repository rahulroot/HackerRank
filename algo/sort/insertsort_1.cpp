#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void print(vector<int> &v, int n)
{
	for(int i = 0; i < n; ++i)
		cout << v[i] <<' ';
	cout << endl;
}

void insert_sort_1(vector<int> &a, int n)
{
	int tmp = a[n-1];
	a[n-1] = a[n-2];
	print(a,n);	
	bool placed = false;
	for(int j = n-3; j >= 0; --j)
	{
		if(tmp < a[j])
		{
			a[j+1] = a[j];
			print(a,n);
		}
		else
		{
			a[j+1] = tmp;
			placed = true;
			print(a,n);
			break;
		}
	}
	if( (placed == false) && (a[0] > tmp) )
	{
		a[0] = tmp;
		print(a,n);
	}
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> vi(n);
	for(int i = 0; i < n; ++i)
		cin >> vi[i];
	
	insert_sort_1(vi, n);
	return 0;
}
