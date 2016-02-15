#include <map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int q;
	cin >> q;
  map<string, int> ma;
	while(q--)
	{
		int t,marks;
		string nm;
		cin >> t;
		switch(t)
		{
			case 1:
			{
				cin >> nm >> marks;
				ma[nm] += marks;
				//ma.insert(pair<string,int>(nm,marks));
				break;
			}
			case 2:
			{
				cin >> nm;
				ma.erase(nm);
				break;
			}
			case 3:
			{
				cin >> nm;
				map<string, int>::iterator it;
				it = ma.find(nm);
				if(it!=ma.end())
					cout << ma[nm] << endl;
				else
					cout <<"0" << endl;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
