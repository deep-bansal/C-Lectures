#include <bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> > pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

void topkelements(int k)
{
	priority_queue<int,vector<int>,greater<int> >pq;
	int n;
	cin>>n;

	while(n!=-1000)
	{
		if(n!=-1)
		{
			if(pq.size()<k)
			{
				pq.push(n);
			}
			else if(pq.top()<n)
			{
				pq.pop();
				pq.push(n);
			}
		}
		else
		{
			printHeap(pq);
		}
		cin>>n;
	}
}
int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	topkelements(k);
	return 0;
}