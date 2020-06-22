# include <bits/stdc++.h>
# include <unordered_map>

using namespace std;

class graph
{
      map<string , list < string> > mp;

public:

	void addEdge(string x,string y,bool bidirectional = true)
	{
		mp[x].push_back(y);  
		if(bidirectional)
		{
			mp[y].push_back(x);
		}
	}

	void dfs_helper(string src,unordered_map<string ,bool> &visited)
	{
		cout<< src << " ";
		visited[src] = true;

		for (auto nbr : mp[src])
		{
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited);
			}
		}
		return;
	}

	void dfs(string src)
	{
		unordered_map<string ,bool> visited;
		for(auto vertex : mp)
		{
			visited[vertex.first] = false; 
		}
		dfs_helper(src,visited);
		cout<<endl;
	}
	void printList ()
	{
		for(auto pr : mp )
		{
			string vertex = pr.first;
			list <string  > neighbours = pr.second;
			cout<< vertex <<"-->";

			for(auto nbr : neighbours)
			{
				cout<<nbr<<" ";
			}
			cout<<endl;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	graph g;
	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("B", "D");
	g.addEdge("B", "C");
	g.addEdge("C", "E");

	g.dfs("A");
	cout << endl;
	g.printList();

	
	return 0;
}