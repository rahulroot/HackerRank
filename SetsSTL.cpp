#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int q;
	int t, n;
	cin >> q; cin.ignore();
	set<int> s;
	while(q--)
	{
		cin >> t >> n;
		switch(t)
		{
			case 1: 
				s.insert(n);
				break;
			case 2:
				s.erase(n);
				break;
			case 3:
			{
				set<int>::iterator it;
				it = s.find(n);
				if(it!=s.end())
					cout <<"Yes"<<endl;
				else
					cout <<"No"<<endl;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
