#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,num;
	cin>>n;
	vector<int> va;
	for(int i=0;(i<n)&&(cin>>num);++i)
		va.push_back(num);
	
	int q;
	cin>>q;

	while(q--)
	{
		int s;
		cin>>s;
		vector<int>::iterator it;
		if(binary_search(va.begin(), va.end(), s))
		{
			it = find(va.begin(), va.end(), s);
			cout <<"Yes" <<' '<< (it-va.begin())+1 << endl;
		}
		else
		{
			vector<int>::iterator low = lower_bound(va.begin(), va.end(), s);
			cout <<"No" <<' '<< (low-va.begin())+1 << endl;
		}
	}
	return 0;
}
