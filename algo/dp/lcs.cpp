#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
int b[1001][1001] = {0};
int c[1001][1001] = {0};
void print_lcs(const vector<int> &vx, int x_z, int y_z, vector<int> &final);

int lcs(const vector<int> &vx, const vector<int> &vy, vector<int> &final)
{
  int x_z = vx.size();
  int y_z = vy.size();

  /* fill first column of all rows with zero's */
  for(int i = 0; i <= x_z; ++i)
    c[i][0] = 0;

  /* fill first row of all column with zero's */
  for(int j = 0; j <= y_z; ++j)
    c[0][j] = 0;

  for(int i = 0; i < x_z; ++i)
  {
    for(int j = 0; j < y_z; ++j)
    {
      if( vx[i] == vy[j])
      {
        c[i+1][j+1] = c[i][j]+1;
        b[i+1][j+1] = 1;
      }
      else if( c[i][j+1] >= c[i+1][j])
      {
        c[i+1][j+1] = c[i][j+1];
        b[i+1][j+1] = 2;
      }
      else
      {
        c[i+1][j+1] = c[i+1][j];
        b[i+1][j+1] = 3;
      }
    }
  }
  print_lcs(vx, x_z, y_z, final);
}

void print_lcs(const vector<int> &vx, int x, int y, vector<int> &final)
{
  if( x == 0 || y == 0)
    return;  
  
  if(b[x][y] == 1)
  {
    print_lcs(vx, x-1, y-1, final);
    final.push_back(vx[x-1]);
  }
  else if( b[x][y] == 2)
    print_lcs(vx, x-1, y, final);
  else 
    print_lcs(vx, x, y-1, final);
}

int main()
{
  freopen("./sample.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
  vector<int> vx(n);
  vector<int> vy(m);
	for(int i = 0;i < n; ++i)
		cin >> vx[i];
	for(int j = 0;j < m; ++j)
		cin >> vy[j];
  vector<int> final;
  lcs(vx,vy, final);
  vector<int>::iterator it;
  vector<int>::iterator tmp;
  for(it = final.begin(); it!=final.end(); ++it)
  {
    cout << *it;
    tmp = it; 
    if(++tmp != final.end())
      cout <<' ';
  }
  cout << endl;
  return 0;
}
