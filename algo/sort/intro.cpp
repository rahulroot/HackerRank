#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, N;
	cin >> n >> N;
	vector<int> vi(N);
	for(int i = 0;i < N; ++i)
		cin >> vi[i];
	for(int i = 0; i < N; ++i)
	{
		if(vi[i] == n)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
} 
