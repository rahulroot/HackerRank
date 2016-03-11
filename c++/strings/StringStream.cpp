#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> parseInts(string s)
{
	stringstream ss;
	ss << s;
	vector<int> va;
	while(ss)
	{
		char ch;
		int num;
		ss >> num;
		ss >> ch;
		va.push_back(num);
	}
	return va;
}

int main ()
{
	string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for(int i = 0; i < integers.size(); i++) {
      cout << integers[i] << "\n";
  }
 
  return 0;
}

