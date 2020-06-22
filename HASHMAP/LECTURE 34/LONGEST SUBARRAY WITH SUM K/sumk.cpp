#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int  longestSubarrayWithSumk(int  * arr,int  n,int  target)
{
	unordered_map<int,int> mp;

	int prefixSum=0,maxlength=0;

	for (int i = 0; i < n; ++i)
	{
		prefixSum+=arr[i];
		
		if(prefixSum == target)
		{
			maxlength= max(i+1,maxlength);
		}
		int toGet= (prefixSum-target);
		if(mp.count(toGet))
		{
			int currlength= i-mp[toGet];
			maxlength=max(maxlength,currlength);
		}
		else
		{
			mp[prefixSum]=i;
		}
	}
	return maxlength;
}

int main(int argc, char const *argv[])
{
	int n;
	n = 6;
	int arr[10] = {2,1,2,0,-1,2};

	int  length = longestSubarrayWithSumk(arr, n,3);
	cout << "max length of subarray with sum k  is " << length << endl;
	return 0;
}