#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template<typename T>

class graph
{	unordered_map<T, list<T> >mp;
public:
	void addEdge(T x, T y) {
		mp[x].push_back(y);
	}

	void topoSortDFSHelper(T src,unordered_map<T,bool> &visited,list<T> &ans )
	{
		visited[src] = true;
		for(auto nbr : mp[src])
		{
			if(!visited[nbr])
			{
				topoSortDFSHelper(nbr,visited,ans);
			}
		}
		ans.push_front(src);
		return;
	}

	void topoSortDFS()
	{
		unordered_map<T,bool> visited;
		list<T> ans;
		for (auto vertex : mp)
		{
			visited[vertex.first] = false;
		}
		for (auto v : mp)
		{
			if(!visited[v.first])
			{
				topoSortDFSHelper(v.first,visited,ans);
			}


		}
		for(string ele : ans)
		{
			cout<<ele<<" ";
		}
		cout<<endl;
		
	}

	
	
	
};

int main(int argc, char const *argv[])
{
	graph<string> g;
	g.addEdge("10", "diploma");
	g.addEdge("10", "11");
	g.addEdge("11", "12");
	g.addEdge("12", "drop");
	g.addEdge("12", "JEE");
	g.addEdge("12", "DU");
	g.addEdge("drop", "JEE");
	g.addEdge("JEE", "B.Tech");
	g.addEdge("JEE", "B.E.");
	g.addEdge("diploma", "B.Tech");
	g.addEdge("extraordinary", "B.Tech");

	g.topoSortDFS();




	return 0;
}
