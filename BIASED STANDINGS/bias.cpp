#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string name;
		int rank;
		int freq[100000];
		int minRank = INT_MAX,maxRank =INT_MIN;
		memset(freq,0,sizeof freq);
		for (int i = 0; i < n; ++i)
		{
			cin>>name>>rank;
			minRank = min(rank,minRank);
			maxRank = max(rank,maxRank);
			freq[rank]++;
		}
		int sum = 0;
		int actualRank=1;
		for (int i = minRank; i <= maxRank ; ++i)
		{
			if(freq[i]!= 0)
			{
				while(freq[i] != 0)
				{
					sum+=abs(i - actualRank);
					freq[i]--;
					actualRank++;
				}
			}
		}
		cout<<sum<<endl;

	}
	return 0;
}