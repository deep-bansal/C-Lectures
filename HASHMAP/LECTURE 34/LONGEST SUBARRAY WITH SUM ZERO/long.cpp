#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int longestSubarrayWithSumZero(int * arr,int n)
{
	unordered_map<int,int> mp;
	int prefixSum=0,maxlength=0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum+=arr[i];
		if(arr[i]==0 and maxlength==0)// 3,4,0
			{
				maxlength=1;
			}
		if(prefixSum==0)
		{
			maxlength=max(i+1,maxlength);
		}
		if(mp.count(prefixSum))
		{
			int currlength= i-mp[prefixSum];
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
	n = 8;
	int arr[10] = {3,0,-1,2,-1,0,1,-4};
	//prefixArray 3,5,9,7,5,0
	//int arr[10] = {2, -2};
	int length = longestSubarrayWithSumZero(arr, n);
	cout << "max length of subarray with sum 0  is " << length << endl;
	return 0;
}