#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

int knapSack01(int* wt,int* price,int n ,int totalwt)
{
	if(n == 0)
	{
		return 0;
	}
	int inc = 0,exc = 0;

	if(totalwt - wt[n-1] >=0)
	{
		inc = price[n-1] + knapSack01(wt,price,n-1,totalwt - wt[n-1]);

	}
	
		exc = knapSack01(wt,price,n-1,totalwt);
	

	return max(inc , exc) ; 

}

int memo [100][100] = {0} ;
int knapSack01TopDown(int* wt,int* price,int n ,int totalwt)
{
	if(n == 0)
	{
		return 0;
	}

	if(memo[n][totalwt] != 0)
	{
		return memo[n][totalwt];
	}

	int inc = 0,exc = 0;

	if(totalwt - wt[n-1] >=0)
	{
		inc = price[n-1] + knapSack01TopDown(wt,price,n-1,totalwt - wt[n-1]);

	}

		exc = knapSack01TopDown(wt,price,n-1,totalwt);

	

	memo[n][totalwt] = max(inc ,exc);

	return memo[n][totalwt]; 

}

int knapsack01BottomUpDP (int* price ,int *wt , int n ,int totalwt)
{
	int dp[n+1][totalwt+1];

	if(n == 0)
	{
		return 0;
	}

	for(int  i = 0; i<= n; i++)
	{
		for(int j = 0 ; j<= totalwt ;j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
		}
	}

	for (int item = 1; item <= n; ++item)
	{
		for (int weight = 1; weight <= totalwt ; ++weight)
		{
			int inc = 0, exc = 0;
			exc = dp[item -1][weight];

			if(weight - wt[item -1] >= 0  )
			{
				inc = price [item -1] + dp[item - 1][weight - wt[item -1]];
			}

			dp[item][weight] = max(inc,exc);
		}
	}
	cout<<endl;
	for (int i = 0; i <= n; ++i)
	{
		for(int j = 0 ; j<= totalwt; j++)
		{
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][totalwt];
}



int main(int argc, char const *argv[])
{
	
	int n = 3;
	int totalWeight = 5;
	int wt[10] = {1, 2, 3};
	int price[10] = {6, 10, 12};
	cout << knapSack01(wt, price, n, totalWeight) << endl;
    cout << knapSack01TopDown(wt, price, n, totalWeight)<<endl;

    for (int i = 0; i <= n; ++i)
	{
		for(int j = 0 ; j<= totalWeight; j++)
		{
			cout<< memo[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout << knapsack01BottomUpDP(price,wt, n, totalWeight) << endl;
	return 0;
}