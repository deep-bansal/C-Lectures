#include <bits/stdc++.h>
using namespace std;

int costToConnect(int* ropes,int n)
{
	priority_queue<int,vector<int>,greater<int> >pq(ropes,ropes+n);

	int totalCost=0;
	while(pq.size()>1)
	{
		int ropeA= pq.top();
		pq.pop();
		int ropeB=pq.top();
		pq.pop();

		int currCost=ropeA+ropeB;
		pq.push(currCost);

		totalCost+=currCost;
	}
	return totalCost;

}
int main(int argc, char const *argv[])
{
	int n=5;
	int arr[n]={2,3,4,6,7};
	int ans= costToConnect(arr,n);
	cout<<ans<<endl;
	return 0;
}