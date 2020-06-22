#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Edge {
public:
	int src;
	int dest;
	int wt;

};

class graph
{	int V;
	int E;
	vector <Edge> edges;
public:
	graph(int n, int e) {
		V = n;
		E = e;
		edges.reserve(E);
	}

	void addEdge(int u, int v, int weight, int edgeNum)
	{
		edges[edgeNum].src = u;
		edges[edgeNum].dest = v;
		edges[edgeNum].wt = weight;
	}
	void BellmanFord(int src)
	{
		vector<int>dist(V);
		for (int i = 0; i < V; ++i)
		{
			if (i == src)
			{
				dist[i] = 0;
			}
			else
			{
				dist[i] = INT_MAX;
			}
		}
		for (int i = 0; i < V - 1; ++i)
		{
			for (int j = 0; j < E ; ++j)
			{
				int srcs = edges[j].src;
				int des = edges[j].dest;
				int weigts = edges[j].wt;

				if (dist[srcs] != INT_MAX and dist[srcs] + weigts < dist[des])
				{
					dist[des] = dist[srcs] + weigts;
				}
			}
		}
		for (int i = 0; i < E; ++i)
		{
			int srcs = edges[i].src;
			int des = edges[i].dest;
			int weigts = edges[i].wt;

			if (dist[srcs] != INT_MAX and (dist[srcs] + weigts < dist[des])) {
				cout << "negative cycle exists from " << srcs << " to " << des << endl;
				return;
			}
		}
		for (int i = 0; i < V; ++i)
		{
			cout << i << " - " << dist[i] << endl;
		}


	}




};

int main(int argc, char const *argv[])
{
	int vertices = 7, edges	= 8;
	graph g(vertices, edges);

	g.addEdge(0, 1, 4, 0);
	g.addEdge(0, 6, 2, 1);
	g.addEdge(1, 2, 3, 2);
	g.addEdge(2, 3, 3, 3);
	g.addEdge(3, 4, -5, 4);
	g.addEdge(4, 5, 2, 5);
	g.addEdge(2, 4, 1, 6);
	g.addEdge(6, 4, 2, 7);

	g.BellmanFord(0);

	return 0;
}
