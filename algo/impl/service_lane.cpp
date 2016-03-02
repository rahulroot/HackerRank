#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
		freopen("./sample.txt", "r", stdin);
    int n;
    int t;
    cin >> n >> t;
    int v[100001];
    for(int width_i = 0;width_i < n;width_i++){
       cin >> v[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
				cout << *min_element(v+i, v+j+1) << endl;
    }
    return 0;
}
