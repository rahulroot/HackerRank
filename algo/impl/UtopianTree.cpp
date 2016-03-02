#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++){
      int n;
      cin >> n;
			int h = 1;
			bool sp = true, sum = false;
			for(int i = 0; i < n; ++i)
			{
				if(sp) { 
					h = h*2;
					sum = true;
					sp = false;
					continue;
				}
				if(sum) {
					h = h + 1;
					sp = true;
					sum = false;
					continue;
				}
			}
			cout << h << endl;
  }
  return 0;
}
