#include <iostream>
#include <cstdlib>
using namespace std;

void update( int *pa, int *pb)
{
	int old_pa = *pa;
	*pa = *pa + *pb;
	*pb = abs(old_pa - *pb);
}

int main()
{
	int a, b;
	cin >> a; cin.ignore();
	cin >> b; cin.ignore();
	int *pa = &a, *pb = &b;
	
	update(pa,pb);
	cout << *pa << endl << *pb << endl;
	return 0;
}
	
