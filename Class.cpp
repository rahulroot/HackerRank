#include <iostream>
#include <sstream>
using namespace std;

class Student
{
	public:
		void set_age(int arg) { age = arg; }
		void set_standard(int arg) { standard = arg;}
		void set_first_name(string arg) { first_name = arg;}
		void set_last_name(string arg) { last_name = arg; create_string();}

		int get_age() { return age;}
		string get_last_name() { return last_name; }
		string get_first_name() { return first_name; }
		int get_standard() { return standard; }
		string to_string() {return ss.str(); } 
		void create_string() { 
			ss << age <<','<< first_name <<','<< last_name <<','<< standard << endl;
		}
	private:
		int age, standard;
		string first_name, last_name;
		stringstream ss;


};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
