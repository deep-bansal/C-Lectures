#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;   

int longestincsubseq(int* arr,int n )
{
	int dp[n]={0};
	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
	}
	int maxlength = 0;

	for (int i = 1; i < n ; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[i]>arr[j])
			{
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		maxlength = max(dp[i],maxlength);
	}
	return maxlength;
}
int optlongestincsubseq(int* arr,int n)
{
	vector<int>v;
	v.push_back(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		auto Ele = lower_bound(v.begin(),v.end(),arr[i]);
		if(Ele == v.end())
		{
			v.push_back(arr[i]);
		}
		else
		{
			*Ele = arr[i] ; /// because it returns a address;

		}
	}
	return v.size();
}
int main(int argc, char const *argv[])
{
	int n= 6;
	int arr[n] = {50,3,10,7,40,50};
	cout<<longestincsubseq(arr,n)<<endl;
	cout<<optlongestincsubseq(arr,n)<<endl;
	return 0;
}