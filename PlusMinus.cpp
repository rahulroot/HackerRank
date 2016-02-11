#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int pos,neg,zero;
	pos = neg = zero = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if(a[i] > 0) pos++;
		else if(a[i] < 0) neg++;
		else zero++;
	}
	std::cout.precision(6);
	cout << std::fixed << float(pos)/n << endl;
	cout << std::fixed << float(neg)/n << endl;
	cout << std::fixed << float(zero)/n << endl;

	return 0;
}
