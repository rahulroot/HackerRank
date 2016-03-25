#include <bits/stdc++.h>
using namespace std;



int main()
{
	freopen("./sample.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	
	vector< int > sq;
	vector <int >:: iterator it;
  sq.push_back(v[0]);
  for(int i=1;i<n;i++)
  {
    if(v[i] >  *(sq.rbegin()))
    {
       sq.push_back(v[i]);
    }
    else
    {
      it = lower_bound(sq.begin(),sq.end(),v[i]);
      *it=v[i];
    }
    for(int j=0;j<sq.size();j++)
			cout<<sq[j]<<" ";
		cout<<endl;
  }
  cout<<sq.size()<<endl;
}

