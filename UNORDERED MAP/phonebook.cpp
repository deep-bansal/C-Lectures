#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<string , vector<string> > phonebook;

	phonebook["Rahul"].push_back("98745");
	phonebook["Rahul"].push_back("987775");
	phonebook["Rahul"].push_back("987458");

	for(auto s:phonebook)
	{
		cout<<s.first<<" ";
		for(auto x: s.second)
		{
			cout<<x<<endl;
		}
	}

	return 0;
}