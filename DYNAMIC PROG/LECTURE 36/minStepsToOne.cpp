#include <bits/stdc++.h>
using namespace std;

int minStepsToOne(int n)
{
	if (n == 1)
	{
		return 0;
	}

	int div3 = INT_MAX, sub1 = INT_MAX, div2 = INT_MAX;

	if (n % 3 == 0 )
	{
		div3 = minStepsToOne(n / 3);
	}

	if (n % 2 == 0)
	{
		div2 = minStepsToOne(n / 2);
	}
	sub1 = minStepsToOne(n - 1);

	int minStepsreqd = 1 + min(div3, min(sub1, div2));

	return minStepsreqd;
}

int memo[1000] = {0};

int minStepsToOneToptoBottom(int n)
{
	if (n == 1)
	{

		return 0;
	}

	if (memo[n] != 0)
	{
		return memo[n];
	}

	int div3 = INT_MAX, sub1 = INT_MAX, div2 = INT_MAX;

	if (n % 3 == 0 )
	{
		div3 = minStepsToOneToptoBottom(n / 3);
	}

	if (n % 2 == 0)
	{
		div2 = minStepsToOneToptoBottom(n / 2);
	}
	sub1 = minStepsToOneToptoBottom(n - 1);

	int minStepsreqd = 1 + min(div3, min(sub1, div2));

	memo[n] = minStepsreqd;

	return memo[n];

}

int minStepsToOneBottomtoTop(int n)
{
	int* dp = new int [n + 1];
	dp[1] = 0; dp[2] = 1; dp[3] = 1;

	for (int i = 4; i <= n ; ++i)
	{
		int div3 = INT_MAX, sub1 = INT_MAX, div2 = INT_MAX;

		if (i % 3 == 0 )
		{
			div3 = dp[i / 3];
		}

		if (i % 2 == 0)
		{
			div2 = dp[i / 2];
		}
		sub1 = dp[i - 1];

		dp[i] = 1 + min(div3, min(div2, sub1));

	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << minStepsToOne(n) << endl;
	cout << minStepsToOneToptoBottom(n) << endl;
	cout << minStepsToOneBottomtoTop(n) << endl;

	return 0;
}