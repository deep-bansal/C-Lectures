#include<bits/stdc++.h>
using namespace std;

int freq[100000];



class compareClass
{
public:
	bool operator()(int a , int b)
	{
		if (freq[a] > freq[b])
		{
			return a < b;
		}
		else if (freq[a] <= freq[b])
		{
			return a > b;
		}

	}

};

void printMin(priority_queue<int, vector<int>, compareClass> pq, int i, int k)
{
	priority_queue<int, vector<int>, compareClass> copy = pq;
	
	if(i < k)
	{
		for (int j = 0; j <= i ; ++j)
		{
			cout<<copy.top()<<" ";
		    copy.pop();
		}
	}
	else
	{
		for (int j = 0; j < k ; ++j)
		{
			cout<<copy.top()<<" ";
		    copy.pop();
		}

	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		memset(freq, 0, sizeof(freq));
		priority_queue<int, vector<int>, compareClass> pq;
		for (int i = 0; i < n; ++i)
		{
			int d;
			cin >> d;
			freq[d]++;			
			pq.push(d);			
			if (i < k)
			{
				printMin(pq, i, k);
			}
			else
			{
				printMin(pq, k, k);
			}


		}
		
	}
	return 0;
}