#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool subarrayWithSumZero(int* arr, int n)
{
	unordered_map<int,int> mp;
	int prefixSum=0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum+=arr[i];
		if( prefixSum==0 or (mp.count(prefixSum) and mp[prefixSum] != i) )
		{
			cout<<mp[prefixSum]+1<<" "<<i<<endl;
			return true;
		}
		else
		{
			mp[prefixSum]=i;
			// we are storing indexes as  values and prefix sum as keys;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	n=6;

	int arr[6]={3, 2, 4, -2, -2, -5};
	if(subarrayWithSumZero(arr,n))
	{
		cout<<"YES subarrayWithSumZero exist"<<endl;
	}
	else
	{
		cout<<"NO it does not exist"<<endl;
	}
	return 0;
}