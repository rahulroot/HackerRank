#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string str;
		cin >> str;
		char c = '0';
		int sz = str.size();
		int cnt = 0;
		for(int i = 0; i < sz; ++i)
		{
			if(c != str[i]) c = str[i];
			else
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
