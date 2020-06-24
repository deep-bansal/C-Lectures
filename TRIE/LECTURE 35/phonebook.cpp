#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
class node
{

public:
	int  data;
	bool isTerminated;
	string username;
	unordered_map<int, node*> children;

	node(int d)
	{
		data = d;
		isTerminated = false;
		username="";
	}
};

class trie
{
public:
	node* root;

	trie()
	{
		root = new node('\0');
	}

	void insert (string word,string name)
	{
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			int ch = word[i] - '0';
			if (!temp-> children. count (ch)) /// means char not already present
			{
				node* child = new node (ch);
				temp->children[ch] = child;
			}
			temp = temp->children[ch];
		}
		temp -> isTerminated = true;
		temp->username = name;
	}

	string  search (string word)
	{
		node* temp = root;
		string ans = "";
		for (int i = 0; i < word.length(); ++i)
		{
			int ch = word[i] - '0';
			if (!temp->children.count(ch))

			{
				return ans;
			}
			temp = temp->children[ch];
		}
		return temp->username;
	}

};

int main(int argc, char const *argv[])
{
	trie t;
	int n;
	cin >> n;

	while (n--) {
		string number, username;
		cin >> number >> username;

		t.insert(number, username);
	}

	int q;
	cin >> q;
	while (q--) {
		string number;
		cin >> number;
		if (t.search(number) != "") {
			cout << number << " is registered for " << t.search(number) << endl;
		} else {
			cout << number << " is not registered" << endl;
		}

	}
}