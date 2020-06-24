#include<bits/stdc++.h>
using namespace std;

class Student 
{
public:
	string name;
	int marks;
};

void bucketSort(Student* arr,int n)
{
	vector<Student> v[101];

	for (int i = 0; i < n; ++i)
	{
		int m = arr[i].marks;
		v[m].push_back(arr[i]);
		
	}

	for(int i = 100;i>=0;i--)
	{
		for(auto x : v[i])
		{
			cout<<x.name<<" "<<x.marks<<endl;
		}
	}

}

int main(int argc, char const *argv[])
{
	Student s[1000];
	int n;
	cin>>n;
	for (int i = 0; i < n ; ++i)
	{
		cin>>s[i].marks>>s[i].name;
	}

	bucketSort(s,n);
	return 0;
}