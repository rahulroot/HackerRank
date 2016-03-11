#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
void printKMax(int arr[], int n, int k)
{
	bool done = false;
  int m,in=0;
	/* fina max in first segment */
 	m = arr[0];
	/* in is index of max element */
	for(int i = 1; i < k; ++i)
	{
   	if(arr[i] > m)
		{
     	m = arr[i];
			in = i;
   	}	
	}	
	cout << m << ' ';
  for(int i = k; i < n; ++i)
  {
		if( i-k+1 > in)
		{
			/* initialize the max again */
			m = arr[i-k+1];
			for(int j = i-k+1; j <= i; ++j)
			{
				if(arr[j] > m)
				{
					m = arr[j];
					in = j;
				}
			}
			cout << m <<' ';
		}
		else if( arr[i] > m )
		{
				m = arr[i];
				in = i;
				cout << m <<' ';
		}
		else
			cout << m <<' ';
  }
	cout << endl;
}
int main()
{
  int t;
	freopen("./sample.txt", "r", stdin);
  cin >> t;
  int arr[10001] = {};
  while(t>0)
  {
    int n,k;
    cin >> n >> k;
    int i, num;
    for(i=0;(i<n)&&(cin>>num);i++)
       arr[i] = num;
    printKMax(arr, n, k);
    t--;
    memset(arr, 0, 10001);
  }
  return 0;
}
