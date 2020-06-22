#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int longestsubseq(int* arr,int n)
{
	unordered_map<int,int>mp;
	int maxlength=0;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]]=i;
	}

	for (int i = 0; i < n; ++i)
	{
		if(mp.count(arr[i]-1))
		{
			continue;
		}
		else
		{
			int count=0;
			int temp=arr[i];
			while(mp.count(temp))
			{
				count++;
				temp++;
			}
			maxlength=max(maxlength,count);
		}
	}
	return maxlength;
}

int main(int argc, char const *argv[])
{
	int arr[]={8,6,3,1,2,1,9,3,4,2,6};
	cout<<longestsubseq(arr,11)<<endl;

	
	return 0;
}