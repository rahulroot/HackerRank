#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
	public:
		int age;
		string name;
		Person() { } 		
		virtual ~Person() { }
		virtual void getData() = 0;
		virtual void putData() = 0;
};

class Professor : public Person
{
	public:
		int pub;
		static int cur_id;
		int id;
		void getData()
		{
			cin >> name;
			cin >> age;
			cin >> pub;
			id = cur_id;
		}
		void putData()
		{
			cout << name <<' '<< age <<' '<< pub <<' '<< id << endl;
		}
		Professor() { id = 0; cur_id++; }
};

class Student : public Person
{
	public:
		vector<int> marks;
		static int cur_id;
		int id;
		Student() { id = 0; cur_id++; }
		void getData()
		{
			cin >> name;
			cin >> age;
			for(int i = 0;i < 6; ++i)
			{
				int num;
				cin >> num;
				marks.push_back(num);
			}
			id = cur_id;
		}
		int sum()
		{
			int num = 0;
			for(int i = 0;i < 6;++i)
				num += marks[i];
			return num;
		}
		void putData()
		{
			cout << name <<' '<< age <<' '<< sum() <<' '<< id << endl;
		}
};

int Student::cur_id = 0;
int Professor::cur_id = 0;

int main()
{
	int n, val;
	cin >> n;
	Person *per[n];

	for(int i = 0; i < n; i++)
	{
		cin >> val;
		if(val == 1)
		{
			per[i] = new Professor;
		}
		else
			per[i] = new Student;
		
		per[i]->getData();

	}

	for(int i = 0; i < n; i++)
		per[i]->putData();
	return 0;
}
