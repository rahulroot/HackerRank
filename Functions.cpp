#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
	vector<int> n;
	n.push_back(a);
	n.push_back(b);
	n.push_back(c);
	n.push_back(d);
	sort(n.begin(), n.end());
	return n.at(3);
}

int main()
{
	int a, b, c, d;
	cin >> a; cin.ignore();
	cin >> b; cin.ignore();
	cin >> c; cin.ignore();
	cin >> d; cin.ignore();

	cout << max_of_four(a, b, c, d) << endl;
	return 0;
}
