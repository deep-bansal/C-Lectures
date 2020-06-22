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

	void shortestDist(string src)
	{
		queue <string> q;
		map<string ,int >distance;

		q.push(src);
		distance [src] = 0;
		while(!q.empty())
		{
			string frontnode = q.front();
			q.pop();
			for(auto nbr : mp[frontnode])
			{
				if(distance.count(nbr) == 0)
				{
					q.push(nbr);
					distance[nbr] = distance[frontnode] + 1;
				}
			}
		}
		for (auto dist : distance)
		{
			string vertex = dist.first;
			cout << vertex << " -> " << dist.second<<" ";

		}
		cout << endl;

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
	g.addEdge("D", "E");
	g.addEdge("C", "E");

	g.shortestDist("A");

	g.printList();

	
	return 0;
}