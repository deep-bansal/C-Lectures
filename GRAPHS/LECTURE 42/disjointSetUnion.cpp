#include <bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	int connectedComponents;
	vector<int> parent;
public:
	graph(int n) {
		V = n;
		connectedComponents = n;
		parent.reserve(n);
		for (int i = 0; i < V; ++i)
		{
			parent[i] = i;
		}
	}

	int getSuperParent(int x) {
		if (parent[x] == x) {
			return x;
		}
		else {
			parent [x] = getSuperParent(parent[x]);
			return parent[x];
		}
	}

	void unite(int u, int v) {
		int parU = getSuperParent(u);
		int parV = getSuperParent(v);

		if (parU != parV) {
			parent[parU] = parV;
			connectedComponents--;
		}
	}


};


int main(int argc, char const *argv[])
{
	int n = 7;
	graph g(7);

	return 0;
}