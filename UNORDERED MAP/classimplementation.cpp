#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class student
{
public:
	string firstname;
	string lastname;
	string rollno;

	student(string f, string l, string r)
	{
		firstname = f;
		lastname = l;
		rollno = r;
	}
	bool operator == (const student &s)const
	{
		return rollno == s.rollno ? true : false;
	}

};

class HashFn
{
public:
	size_t operator ()(const student &s)const
	{
		return s.firstname.length() + s.lastname.length();
	}

};

int main(int argc, char const *argv[])
{
	unordered_map <student, int ,HashFn> student_map;

	student s1("Prateek","Narang","010");
	student s2("Rahul","Kumar","023");
	student s3("Prateek","Gupta","030");
	student s4("Rahul","Kumar","120");

	student_map[s1]=100;
	student_map[s2]=120;
	student_map[s3]=11;
	student_map[s4]=45;

	for(auto s: student_map)
	{
		cout<<s.first.firstname<<" "<<s.first.rollno<<" marks "<< s.second<<endl;
	}


	return 0;
}