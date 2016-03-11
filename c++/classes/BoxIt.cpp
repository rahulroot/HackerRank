#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box
{
	private:
		int l,b,h;
	public:
		Box() { 
			l = b = h = 0; 
			BoxesCreated++;
		}
		Box(int ar1, int ar2, int ar3) { 
			l = ar1;
			b = ar2;
			h = ar3;
			BoxesCreated++;
		}
		Box(const class Box &rh) {
			l = rh.l;
			b = rh.b;
			h = rh.h;
			BoxesCreated++;
		}
		~Box() { 
			BoxesDestroyed++;
		}
	
		int getLength() { return l; }
		int getBreadth() { return b; }
		int getHeight() { return h; }

		long long CalculateVolume() { return (long long)l * b * h; }
		bool operator < ( const class Box &box)
		{
			if(l < box.l ) return true;
			else if( (l == box.l) && (b < box.b) ) return true;
			else if( (l == box.l) && (b == box.b) && (h < box.h)) return true;
			else return false;
		}

		friend ostream& operator << (ostream &out, const class Box a)
		{
			out << a.l <<' '<< a.b <<' '<< a.h;
			return out;
		}
};

void check2()
{
	int n;
  cin>>n;
  Box temp;
  for(int i=0;i<n;i++)
  {
    int type;
    cin>>type;
    if(type ==1)
    {
      cout<<temp<<endl;
    }
    if(type == 2)
    {
        int l,b,h;
        cin>>l>>b>>h;
        Box NewBox(l,b,h);
        temp=NewBox;
        cout<<temp<<endl;
    }
    if(type==3)
    {
        int l,b,h;
        cin>>l>>b>>h;
        Box NewBox(l,b,h);
        if(NewBox<temp)
        {
           cout<<"Lesser"<<endl;
        }
        else
        {
           cout<<"Greater"<<endl;
        }
    }
    if(type==4)
    {
       cout<<temp.CalculateVolume()<<endl;
    }
    if(type==5)
    {
       Box NewBox(temp);
       cout<<NewBox<<endl;
    }

  }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}

