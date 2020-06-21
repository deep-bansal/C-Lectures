#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

int wineRec (int* arr ,int start ,int end,int year)
{
	if(start > end)
	{
		return 0;
	}	

	int startInc = (arr[start] * year) + wineRec (arr,start +1, end , year+1);
	int endInc = (arr[end] * year) + wineRec (arr,start , end -1, year+1);

	int profit = max(startInc,endInc);

	return profit ;
}

int memo [100][100] = {0};
int wineTopDown (int* arr ,int start ,int end,int year)
{

	if(start > end)
	{
		return 0;
	}	
	if(memo[start][end] != 0)
	{
		return memo[start][end];
	}

	int startInc = (arr[start] * year) + wineTopDown (arr,start +1, end , year+1);
	int endInc = (arr[end] * year) + wineTopDown (arr,start , end -1, year+1);
	int profit = max(startInc,endInc);
	memo[start][end] = profit;

	return memo[start][end] ;
}

int wineBottomUpDp(int* arr, int n) {
	int year = n;
	int dp[100][100] = {0};

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = arr[i] * year;
	}

	year--;

	for (int window = 2; window <= n; window++)
	{
		int start = 0, end = n - window;
		while (start <= end) {
			int endOfcurrWindow = start + window - 1;
			dp[start][endOfcurrWindow] = max(
			                                 (arr[start] * year) + dp[start + 1][endOfcurrWindow],
			                                 (arr[endOfcurrWindow] * year) + dp[start][endOfcurrWindow - 1]);
			start++;
		}

		year--;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}

	return dp[0][n - 1];



}

int main(int argc, char const *argv[])
{
	int arr[10] = {2, 3, 5, 1, 4};
	int n = 5;
	cout << wineRec(arr, 0, n - 1, 1) << endl;
	int dp[100][100] = {0};
	cout << wineTopDown(arr, 0, n - 1, 1) << endl;
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			cout<<memo[i][j]<<" ";
		}
		cout<<endl;
	}
	 cout << wineBottomUpDp(arr, n) << endl;


	return 0;
}