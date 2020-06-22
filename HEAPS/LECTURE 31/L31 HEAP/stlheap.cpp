#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//by default max heap is formed
	priority_queue <int> pq;
	
	pq.push(10);
	pq.push(20);
	pq.push(40);
	pq.push(60);
	pq.push(15);

	cout<<"size "<<pq.size()<<endl;
	cout<<pq.top()<<" ";
	pq.pop();
	cout<<pq.top()<<" ";
	pq.pop();
	cout<<pq.top()<<" ";
	pq.pop();
	cout<<pq.top()<<" ";
	pq.pop();
	cout<<pq.top()<<" ";
	pq.pop();

	/// to build min heap
	priority_queue <int, vector <int>,greater<int> >pq2;
	return 0;
}