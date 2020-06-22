#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool targetSumPair(int* arr,int n,int target)
{
	unordered_map<int,int> mp;

	for (int i=0;i<n;i++)
	{
		int toGet=target-arr[i];
		if(mp.count(toGet))
		{
			cout<<arr[mp[toGet]]<<"  "<<arr[i]<<endl;
			return true;
		}
		else
		{
			mp[arr[i]]=i;
		}

	}
	return false;
}
	


int main(int argc, char const *argv[])
{
	int n;
	n = 6;
	int arr[10] = {3, 2, 4, -1, -2, -5};

	if (targetSumPair(arr, n, -3)) {
		cout << "pair exists" << endl;
	} else {
		cout << "pair doesn't exists" << endl;
	}
	return 0;
}