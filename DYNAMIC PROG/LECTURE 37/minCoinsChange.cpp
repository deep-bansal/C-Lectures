#include <bits/stdc++.h>
using namespace std;

int minCoinsExc(int money,int* coins,int numcoins)
{
	if(money == 0)
	{
		return 0;
	}

	int count = 0;
	int ans= 66565;  /// yha pr

	for (int i = 0; i < numcoins; ++i)
	{
		if(money - coins[i]>=0)
		{
			int count = minCoinsExc(money - coins[i],coins,numcoins);
			ans= min (ans,count+1);	
		}
	}
	return ans;
}

int memo[1000]={0};

int minCoinsExcTopToBottom(int money,int* coins,int numcoins)
{
	if(money == 0)
	{
		return 0;
	}
	if(memo[money]!=0)
	{
		return memo[money];
	}

	int count = 0;
	int ans= 66666;  /// yha pr

	for (int i = 0; i < numcoins; ++i)
	{
		if(money - coins[i]>=0)
		{
			int count = minCoinsExcTopToBottom(money - coins[i],coins,numcoins);
			ans= min (ans,count+1);	
		}

	}
	memo[money] = ans;
	return memo[money];

}

int minCoinsExcBottomToTop(int money,int* coins,int numcoins)
{
	int dp[money+1]={0};

	for (int i = 1; i <= money; ++i)
	{
	    dp[i]= INT_MAX;
		for(int coin = 0; coin< numcoins ; coin++)
		{
			if (i - coins[coin] >= 0) {
				int reqCoins = dp[i - coins[coin]];
				dp[i] = min(dp[i], reqCoins + 1);
			}

		}
	}
	/*for (int i = 1; i <= money; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;*/


	return dp[money];
}

int main(int argc, char const *argv[])
{
	int money;
	cin>>money;
	int coins[10]={2,7,10};
	int numCoins = 3;
	cout<< minCoinsExc(money,coins,numCoins)<<endl;
	cout<< minCoinsExcTopToBottom(money,coins,numCoins)<<endl;
    cout<< minCoinsExcBottomToTop(money,coins,numCoins)<<endl;
	return 0;
}