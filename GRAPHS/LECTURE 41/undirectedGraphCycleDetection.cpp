# include <bits/stdc++.h>
# include <unordered_map>
using namespace std;

template <typename T>
class graph
{
	map<T , list <T> > mp;

public:

	void addEdge(T x, T y, bool bidirectional = true)
	{
		mp[x].push_back(y);
		if (bidirectional)
		{
			mp[y].push_back(x);
		}
	}

	bool undirectedCycleDetectHelper(T src, unordered_map <T, bool> &visited, T parent)
	{
		visited[src] = true;

		for (auto nbr : mp[src])
		{
			if (!visited[nbr])
			{
				if (undirectedCycleDetectHelper(nbr, visited, src))
				{
					return true;
				}

			}
			else if (nbr != parent)
			{
				return true;
			}
		}
		return false;
	}

	void undirectedCycleDetect(T src)
	{
		unordered_map <T, bool> visited;

		for (auto vertex : mp)
		{
			visited[vertex.first] = false;
		}
		if (undirectedCycleDetectHelper(src, visited, ""))
		{
			cout << "Cycle Exist" << endl;
		}
		else
		{
			cout << "Cycle Doesn't Exist" << endl;
		}

	}
	void printList() { //to print adjacency list

		for (auto pr : mp)
		{
			T vertex = pr.first;

			cout << vertex << " --> ";
			for (auto nbr : pr.second)
			{
				cout << nbr << ", ";
			}

			cout << endl;
		}

	}
};

int main(int argc, char const *argv[])
{
	graph<string> g;
	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("B", "D");
	g.addEdge("C", "D");
	g.addEdge("C", "E");
	g.addEdge("E", "F");

	g.undirectedCycleDetect("A");

	g.printList();


	return 0;
}
