#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_palin(string &s)
{
        int len = s.size();
        if( len < 2 ) return true;
        for( int i = 0; i < (int)len/2; ++i)
        {
                if( s[i] != s[len-i-1])
                        return false;
        }
        return true;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int cnt = 0;
		string s;
		cin >> s;
		int len = s.size();
		if(len < 2) cout << "0" << endl;
		else
		{
			for(int i = 0; i < (int)len/2; ++i)
			{
				if( s[i] != s[len-i-1])
				{
					while(s[i] != s[len-i-1])
					{
						if(s[i] > s[len-i-1])
						{
							s[i] = s[i]-1;
							cnt++;
						}
						else
						{
							s[len-i-1] = s[len-i-1]-1;
							cnt++;
						}
					}
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
