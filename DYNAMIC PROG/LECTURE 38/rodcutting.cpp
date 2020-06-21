#include <bits/stdc++.h>

using namespace std;

int rodcutting(int* arr, int length)
{
	if (length == 0)
	{
		return 0;
	}

	int maxprofit = 0;
	for (int cut = 1; cut < length ; cut++)
	{

		int currprofit = arr[cut] + rodcutting(arr, length - cut);

		maxprofit = max(maxprofit, currprofit);
	}
	return maxprofit;
}
int memo[1000] = {0};

int rodcuttingTopDown(int* arr, int length)
{
	if (length == 0)
	{
		return 0;
	}

	if (memo[length] != 0)
	{
		return memo[length];
	}

	int maxprofit = 0;
	for (int cut = 1; cut < length ; cut++)
	{

		int currprofit = arr[cut] + rodcutting(arr, length - cut);

		maxprofit = max(maxprofit, currprofit);
	}
	memo[length] = maxprofit;
	return maxprofit;
}

int rodcuttingBottomUp(int* arr, int n)
{
	int dp[n] = {0};
	dp[0]=0;

	for (int i = 0; i < n ; ++i)
	{
		int currProfit = 0;
		for (int cut = 0; cut <= i ; ++cut)
		{
			currProfit = max(currProfit, dp[i - cut] + arr[cut]);
		}

		dp[i] = currProfit;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout<<endl;
	return dp[n-1];
}


int main(int argc, char const *argv[])
{
	int n = 9;
	int arr[10] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
	cout << rodcutting(arr, n) << endl;
	cout << rodcuttingTopDown(arr, n) << endl;
	cout << rodcuttingBottomUp(arr, n) << endl;
	return 0;
}