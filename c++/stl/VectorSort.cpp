#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int num,a;
	vector<int> va;
	cin >> num;
	
	for(int i = 0;i < num;++i)
	{
		cin >> a;
		va.push_back(a);
	}

	sort(va.begin(), va.end());
	for(int i = 0;i < num;++i)
		cout << va[i] <<' ';
	cout << endl;

	return 0;
}
	
