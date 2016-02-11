#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
  vector<int> arr(n);
	long int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	cout << sum << endl;
	return 0;
}
	

