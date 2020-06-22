# include <bits/stdc++.h>
# include <unordered_map>

using namespace std;

class graph
{
	unordered_map<int, list<int> > mp;
	//unordered_map<vertex, list<pair<_neighbour_vertex, weight> > >
public:

	void addEdge(int x, int y, bool bidirectional = true)
	{
		mp[x] . push_back(y);
		if (bidirectional)
		{
			mp[y] . push_back(x);
		}
	}

	void bfs (int src)
	{
		queue<int> q;
		bool* visited  = new bool [100];

		q.push(src);
		visited [src] = true;
		while (!q.empty())
		{
			int frontNode = q.front();
			q.pop();
			cout << frontNode << " ";
			for (int nbr : mp[frontNode])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}

		}
		cout<<endl;
	}
	void printList ()
	{
		for (auto pr : mp )
		{
			int vertex = pr.first;
			list <int> neighbours = pr.second;
			cout << vertex << "-->";

			for (auto nbr : neighbours)
			{
				cout << nbr <<" ";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
    graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.bfs(0);

	g.printList();


	return 0;
}