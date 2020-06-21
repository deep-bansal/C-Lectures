#include <bits/stdc++.h>
using namespace std;

int countBoardPathsRec(int start,int end)
{
	if(start == end)
	{
		return 1;
	}
	if(start > end)
	{
		return 0;
	}

	int count =0;
	for (int i = 1; i <= 6 ; ++i)
	{
		count+= countBoardPathsRec(start+i,end);
	}

	return count;
}

int memo[1000]={0};

int countBoardPathsTopDown(int start,int end)
{
	if(start == end)
	{
		return 1;
	}
	if(start > end)
	{
		return 0;
	}
	if(memo[start]!= 0)
	{
		return memo[start];
	}

	int count =0;
	for (int i = 1; i <= 6 ; ++i)
	{
		count+= countBoardPathsRec(start+i,end);
	}
	memo[start]= count;
	return memo[start];

}

int countBoardPathsDownTopRightToLeft(int start,int end)
{
	int dp[end+1]= {0};

	dp[end]=1;
	for (int i = end-1; i >= start; --i)
	{
		for (int dice = 1; dice <= 6 ; ++dice)
		{
			if(i+dice<=end)
			{
				dp[i]+=dp[i+dice];
			}
		}
	}
	cout<<"array --> ";
	for (int i = 0; i <= end; ++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
	return dp[start];
}

int countBoardPathsDownTopLeftToRight (int start,int end)
{
	int dp[end+1]= {0};

	dp[start]=1;
	for (int i = start+1; i <= end; ++i)
	{
		for (int dice = 1; dice <= 6 ; ++dice)
		{
			if(i-dice>=start)
			{
				dp[i]+=dp[i-dice];
			}
		}
	}
	cout<<"array --> ";
	for (int i = 0; i <= end; ++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
	return dp[end];
}

int countBoardPathsDownTopLeftToRightOpti (int start,int end)
{
	int dp[end+1]= {0};

	dp[start]=1;
	dp[start+1]=1;
	int k=6;
	for (int i = start+2; i <= start+k; ++i)
	{
		dp[i]= 2*dp[i-1] ;
	}
    for(int i= start+k+1; i<= end; i++)
    {
    	dp[i]= 2*dp[i-1] - dp[i-k-1];
    }
	cout<<"array --> ";
	for (int i = 0; i <= end; ++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
	return dp[end];

}


int main(int argc, char const *argv[])
{
	int n =10;
	cout<<countBoardPathsRec(0,n)<<endl;
	cout<<countBoardPathsTopDown(0,n)<<endl;
	cout<<countBoardPathsDownTopRightToLeft(0,n)<<endl;
	// cout<<countBoardPathsDownTopLeftToRight(0,n)<<endl;
	// cout<<countBoardPathsDownTopLeftToRightOpti(0,n)<<endl;


	return 0;
}