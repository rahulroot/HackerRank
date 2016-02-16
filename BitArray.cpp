#include <iostream>
#include <bitset>
#include <limits.h>
#include <vector>
const long long int my_max = 2147483648;
using namespace std;

int main()
{
	int n, s, p, q;
	cin >> n >> s >> p >> q;
	bool* a = new bool[n];	

	int ad = my_max-1;
	a[0] = s & ad;
	for(int i =1; i <= n-1; ++i)
	{
		long div = q & ad;
		long mul = (long)a[i-1]*p;
		a[i] = mul+div;
		cout <<"Generatng : " << mul+div << endl;
	}

	int count = 0;
	for(int i = 0; i < n; ++i)
		if(a[i]) count++;

	cout << count << endl;

	delete []a;
	
	return 0;
}
