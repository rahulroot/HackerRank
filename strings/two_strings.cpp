#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string a, b;
		cin >> a >> b;
		map<char, int> freq;
		int sz = a.size();
		for(int i =0; i < sz; ++i)
			freq[a[i]]++; 
		sz = b.size();
		bool found = false;
		for(int i = 0; i < sz; ++i)
		{
			if(freq.find(b[i]) != freq.end())
			{
				found = true;
				break;
			}
		}
		if(found)
			cout <<"YES" << endl;
		else
			cout <<"NO" << endl;
	}
	return 0;
}
