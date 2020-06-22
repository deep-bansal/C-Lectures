#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class graph
{	int V;
	unordered_map<int, list<pair<int, int> > > mp;//weighted graph
//unordered_map<vertex, list<pair<_neighbour_vertex, weight> > >
public:

	graph(int n){
		V = n;
	}

	void addEdge(int x, int y, int weight, bool bidirectional = true) {
		mp[x].push_back(make_pair(y, weight));
		if (bidirectional) {
			mp[y].push_back(make_pair(x, weight));
		}
	}

	int holiHelper(int src,unordered_map<int,pair<bool,int> > &visited,int &maxDistTravelled)
	{
		visited[src] = make_pair(true,1);
		for(auto nbrpair : mp[src])
		{
			int nbr = nbrpair.first;
			int wt =  nbrpair.second;
			if(!visited[nbr].first)
			{
				visited[src].second += holiHelper(nbr,visited,maxDistTravelled);
				int nodeNbr = visited[nbr].second;
				int nodeLeft = V - nodeNbr;
				maxDistTravelled += 2*min(nodeNbr,nodeLeft)*wt;

			}

		}
		return visited[src].second;
	}

	void holi()
	{
		unordered_map<int,pair<bool,int> > visited;

		for (int i = 0; i < V; ++i)
		{
			visited[i] = make_pair(false,0); 
		}

		int maxDistTravelled =0;
		holiHelper(0,visited,maxDistTravelled);
		cout<<maxDistTravelled<<endl;

	}

	

	// void printList() { //to print adjacency list

	// 	for (auto pr : mp)
	// 	{
	// 		int vertex = pr.first;
	// 		list<pair<int, int> > neighbours = pr.second;
	// 		cout << vertex << " --> ";
	// 		for (auto nbr : neighbours)
	// 		{
	// 			int nbr_vertex = nbr.first;
	// 			int nbr_weight = nbr.second;
	// 			cout << "{ " << nbr_vertex << ", " << nbr_weight << " } ";
	// 		}
	// 		cout << endl;
	// 	}

	// }
};

int main(int argc, char const *argv[])
{
	graph g(4);
	g.addEdge(0, 1, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 3, 2);

	g.holi();
	//g.printList();

	return 0;
}