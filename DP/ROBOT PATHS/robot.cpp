#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int robotandPaths(int row,int col)
{
	
	if(dp[0][0]  == -1)
	{
		return 0;
	}

	for (int i = 0; i < col; ++i)
	{
		if(dp[0][i] == -1)
		{
			break;
		}
		dp[0][i] =1;
	}
	for (int i = 0; i < row; ++i)
	{
		if(dp[i][0] == -1)
		{
			break;
		}
		dp[i][0] =1;
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if(dp[i][j] == -1) {continue;}

			dp[i][j] =0;

			if(dp[i][j-1] != -1)
			{
				dp[i][j] = dp[i][j-1];
			}
			if(dp[i-1][j] != -1)
			{
				dp[i][j] += dp[i-1][j];
			}
		}

		

	}
	if(dp[row-1][col-1] == -1)
		{
			return 0;
		}
		return dp[row-1][col-1];
}


int main(int argc, char const *argv[])
{
	memset(dp,0,sizeof(dp));
	int m,n,p;
	cin>>m>>n>>p;

	for (int i = 0; i < p; ++i)
	{
		int x,y;
		cin>>x>>y;
		dp[x-1][y-1] =-1;
	}

	cout<<robotandPaths(m,n)<<endl;


	return 0;
}