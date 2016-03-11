#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
	public:
		Matrix() {}
 	 ~Matrix() {}
		void set_row(int n) { row = n; }
		void set_col(int m) { col = m; }
		friend Matrix operator + (const Matrix &a, const Matrix &b);
		vector< vector<int> >a;
		int row, col;
};

Matrix operator+(const Matrix &mat_a, const Matrix &mat_b)
{
	Matrix mat_c;
	vector<int> b;

	for(int i = 0; i < mat_a.a.size(); ++i)
	{
		for(int j = 0; j < mat_a.a[0].size(); ++j)
		{
			b.push_back(mat_a.a[i][j] + mat_b.a[i][j]);
		}
		mat_c.a.push_back(b);
		b.clear();
	}
	return mat_c;
}

int main()
{
	int t;
	cin >> t; cin.ignore();
	while(t--)
	{
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
			x.set_row(n); x.set_col(m);
			y.set_row(n); y.set_col(m);
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
