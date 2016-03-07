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
  int k = 0;
  for(int i = 1; i < n; ++i)
  {
    for(int j = n-1; j>=0; --j)
		{
			if(a[j]<a[j-1])
			{
				swap(a[j], a[j-1]);
				k++;
			}
		}
	}
  cout << k << endl;
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

