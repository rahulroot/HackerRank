#include <bits/stdc++.h>
using namespace std;


#define MAX 100002
struct Workshop 
{
	int start_time, duration, end_time;
	Workshop() { }
};

struct Available_Workshops
{
	public:
		int total;
		struct Workshop workshop[MAX];
		Available_Workshops(int arg) { 
			total = arg;
		}
};

Available_Workshops* initialize(int st_time[], int dur[], int n)
{
	Available_Workshops *ptr = new Available_Workshops(n);
	for(int i = 0; i < n; ++i)
	{
		ptr->workshop[i].start_time = st_time[i];
		ptr->workshop[i].duration = dur[i];
		ptr->workshop[i].end_time = st_time[i]+dur[i];
	}
	return ptr;
}

bool compare_on_st(const Workshop &lh, const Workshop &rh)
{
	return lh.end_time < rh.end_time;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
	
	vector<Workshop> vs;
	for(int i = 0; i < ptr->total; ++i)
		vs.push_back(ptr->workshop[i]);

	stable_sort(vs.begin(), vs.end(), compare_on_st);
	int count = 1;
	int i = 0;
	for(int j = 1; j < ptr->total; ++j)
	{
		if(vs[j].start_time >= vs[i].end_time)
		{
			count++;
			i = j;
		}
	}
	
	return count;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
        cin>>start_time[i];
    for(int i=0;i<n;i++)
        cin>>duration[i];
    
    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout << CalculateMaxWorkshops(ptr) << endl;
		delete ptr;
    return 0;
}

