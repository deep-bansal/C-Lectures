# include <bits/stdc++.h>
# include <unordered_map>
using namespace std;

template<typename T>
class graph
{
      map<T , list <T> > mp;

public:

	void addEdge(T x,T y,bool bidirectional = true)
	{
		mp[x].push_back(y);  
		if(bidirectional)
		{
			mp[y].push_back(x);
		}
	}

	void dfs_help(T src,unordered_map <T,bool> &visited,int &astronauts)
	{
		visited[src] = true;
		astronauts++;

		for (auto nbr : mp[src])
		{
			if(!visited[nbr])
			{
				dfs_help(nbr,visited,astronauts);
			}
		}
	}

	int dfs(int n)
	{
		unordered_map <T,bool> visited;

		int countries = 0;
		int totalpairs = (n*(n-1))/2;

		int pairsfromSameCountry = 0;

		for(auto vertex : mp)
		{
			int astronauts = 0;
			if(!visited[vertex.first])
			{
				dfs_help(vertex.first,visited,astronauts);

				pairsfromSameCountry = (astronauts*(astronauts-1))/2;
				totalpairs -= pairsfromSameCountry;
				countries++;
			}
		}
		cout<<countries<<endl;
		return totalpairs;

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
	graph<int> g;
	int n, p;
	cin>>n>>p;
	while(p--)
	{
		int a, b;
		cin>>a>>b;
		g.addEdge(a,b);
	}

	cout<<g.dfs(n)<<endl;
	g.printList();
	

	return 0;
}
