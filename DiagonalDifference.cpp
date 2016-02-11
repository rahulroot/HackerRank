#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	int rows;
	cin >> rows;
	vector< vector<int> > mat(rows, vector<int>(rows));
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0;j < rows; ++j)
		{
			cin >> mat[i][j]; 
		}
	}

	int diag_1 = 0;
	for(int i = 0, j = i; (i < rows) && ( j == i); ++i,++j)
	{
			diag_1 += mat[i][j];
  }	
	int diag_2 = 0;
	for(int i = 0,j = rows-1; (i < rows) && ( j >= 0); ++i, --j)
	{
			diag_2 += mat[i][j];
	}
	cout << abs(diag_1 - diag_2) << endl;
	return 0;
}
