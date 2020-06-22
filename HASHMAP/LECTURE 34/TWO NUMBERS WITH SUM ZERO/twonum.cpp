#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool isSumZero(int* arr,int n)
{
	unordered_map<int,int> mp;

	for(int i=0; i<n; i++)
	{ int toGet= -1*arr[i];
		if(mp.count(toGet))
		{
			cout<<arr[i]<<"  "<<toGet<<endl;
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
	n=6;
	int arr[6]={3,2,4,-1,9,5};

	if(isSumZero(arr,n))
	{
		cout<<"yes zero sum exist"<<endl;
	}
	else
	{
		cout<<"no it does not exist"<<endl;
	}
	return 0;
}