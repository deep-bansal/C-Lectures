#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template<typename T>
class graph
{
	unordered_map<T, list<T> > mp;

public:

	void addEdge(T x, T y, bool bidirectional = true)
	{
		mp[x].push_back(y);
		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	bool dfsHelper(T src, unordered_map<int, bool> &visited, vector<bool> &stack)
	{
		visited[src] = true;
		stack[src] = true;
		for (auto nbr : mp[src])
		{
			if (stack[nbr])
			{
				return true;
			}
			if (visited[nbr] == false)
			{
				if (dfsHelper(nbr, visited, stack))
				{
					return true;
				}
			}
		}
		stack[src] = false;
		return false;
	}

	void dfs(T src)
	{
		unordered_map<int, bool> visited;
		vector<bool> stack;
		stack.reserve(100);
		for(auto vertex : mp)
		{
			visited[vertex.first]=false;
		}
		for (int i = 0; i < 100; ++i)
		{
			stack[i] = false;
		}

		if (dfsHelper(src, visited, stack))
		{
			cout << "cycle Exist" << endl;
		}
		else
		{
			cout << "cycle Doesn't Exist" << endl;
		}
	}



};

int main(int argc, char const *argv[])
{
	graph<int> g;
	g.addEdge(1, 2, false);
	g.addEdge(1, 3, false);
	g.addEdge(2, 4, false);
	g.addEdge(3, 5, false);
	g.addEdge(5, 6, false);
	//g.addEdge(6, 3, false);


	g.dfs(1);

	return 0;
}
