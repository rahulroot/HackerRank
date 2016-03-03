#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
  int d1;
  int m1;
  int y1;
  cin >> d1 >> m1 >> y1;
  int d2;
  int m2;
  int y2;
  cin >> d2 >> m2 >> y2;

	if(y1 > y2)
		cout << "10000" << endl;
	else if( (y2 == y1) && (m1 > m2) )
		cout << 500 * (m1-m2) << endl;
	else if( (y2 == y1) && ( m2 == m1) && ( d1 > d2) )
		cout << 15 * ( d1-d2) << endl;
	else
		cout << "0" << endl;

  return 0;
}
