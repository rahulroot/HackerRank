#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool isZero(int i) { return i == 0; }

int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i =0;i <n; ++i)
		cin >> v[i];

	int sz = v.size();
	while(sz!=0)
	{
		int mel = *min_element(v.begin(), v.end());
		vector<int>::iterator it;
		for(it=v.begin(); it!=v.end(); ++it)
			*it = *it-mel;
		cout << v.size() << endl;
		v.erase(remove_if(v.begin(), v.end(), isZero), v.end());
		sz = v.size();
	}	
	return 0;
}
	
