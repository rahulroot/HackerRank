#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
  int t;
	freopen("./sample.txt", "r", stdin);
  cin >> t;
  for(int a0 = 0; a0 < t; a0++){
    int n;
    cin >> n;
		int rem = 0;
		int count = 0;
		int num = n;
		while(n!=0)
		{
			rem = n%10;
			if( (rem != 0) && (num%rem == 0))
				count++;
			n = n/10;
		}
		cout << count << endl;
  }
  return 0;
}

