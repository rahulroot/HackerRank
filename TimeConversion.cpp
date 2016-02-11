#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main()
{
	string time;
	cin >> time;
	bool am = false;
	string hh = time.substr(0,2);
	string mm = time.substr(3,2);
	string sec = time.substr(6,2);

	if(time.at(8) == 'A')
		am = true;
	else
		am = false;
	int hour = atoi(hh.c_str());
	if(am)
	{
		if( hour == 12)
			hour = 0;
	}
	else
	{
		if(hour != 12)
			hour += 12;
	}
	stringstream ss;
	ss << hour;
	hh = ss.str();
	if( hh.length() == 1) hh = '0' + hh;
	cout << hh <<':'<< mm <<':' << sec << endl;
	return 0;
}
