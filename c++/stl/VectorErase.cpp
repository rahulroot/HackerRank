#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,num;
	cin >> n;
	vector<int> va;
	for(int i=0; (i<n)&&(cin>>num);++i)
		va.push_back(num);
	int pos,a,b;
	cin >> pos;
	va.erase(va.begin()+pos-1);
	cin >> a >> b;
	va.erase(va.begin()+(a-1), va.begin()+(b-1));
	vector<int>::iterator it;
	cout << va.size() << endl;
	for(it=va.begin(); it!=va.end(); ++it)
		cout << *it <<' ';
	cout << endl;
	
	return 0;
	
}
