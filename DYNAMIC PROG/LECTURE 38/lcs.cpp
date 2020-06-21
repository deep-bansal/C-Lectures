#include <bits/stdc++.h>
using namespace std;   
int ans = 0;
int lcs(string s1,string s2)
{
	if(s1.length()==0 or s2.length()==0)
	{
		return 0;
	}
	
	if(s1[0] == s2[0])
	{
		ans = 1 + lcs(s1.substr(1),s2.substr(1));

	}
	else
	{
		ans = max(lcs(s1.substr(1),s2),lcs(s1,s2.substr(1)));
	}
	return ans;
}

int memo[100][100];
int lcsTopBottom(string s1,string s2)
{
	if(s1.length()==0 or s2.length()==0)
	{
		return 0;
	}

	if(memo[s1.size()][s2.size()] != -1)
	{
		return memo[s1.size()][s2.size()];
	}
	int ans = 0;

	if(s1[0] == s2[0])
	{
		ans = 1 + lcsTopBottom(s1.substr(1),s2.substr(1));

	}
	else
	{
		ans = max(lcsTopBottom(s1.substr(1),s2),lcsTopBottom(s1,s2.substr(1)));
	}
	memo[s1.size()][s2.size()] = ans;

	return ans;
}

int lcsBottomTop(string s1,string s2)
{
	int dp[100][100] = {0};

	for (int i = 1; i <= s1.length() ; ++i)
	{
		for (int j = 1; j <= s2.length() ; ++j)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

	}

	for (int i = 0; i <= s1.length(); ++i)
	{
		for (int j = 0; j <= s2.length(); ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[s1.length()][s2.length()];

}

int main(int argc, char const *argv[])
{
    string str1 = "abc";
	string str2 = "acd";
	//cout << lcs(str1, str2) << endl;	
	cout<<lcsBottomTop(str1,str2)<<endl;

	// for (int i = 0; i <= str1.length(); ++i)
	// {
	// 	for (int j = 0; j <= str2.length(); ++j)
	// 	{
	// 		memo[i][j] = -1;
	// 	}
	// }

	// cout << lcsTopBottom(str1,str2) << endl;

	// for (int i = 0; i <= str1.length(); ++i)
	// {
	// 	for (int j = 0; j <= str2.length(); ++j)
	// 	{
	// 		cout<<memo[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}