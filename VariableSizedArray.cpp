#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	int k = 0;
	int *ar[100002];
	while(n--)
	{
		int c,num;
		cin >> c;
		ar[k] = new int[c];
		for(int i = 0; (i<c) &&(cin >> num); ++i)
			ar[k][i] = num;
		k++;
	}

	while(q--)
	{	
		int a, b;
		cin >> a >> b;
		cout << ar[a][b] << endl;
	}

	for(int i = 0;i < n; ++i)
		delete ar[i];

	return 0;
}
