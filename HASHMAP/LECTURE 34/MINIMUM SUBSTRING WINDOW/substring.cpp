#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string  minWindowsubstring(string str,string pat)
{
	int len1=str.length();
	int len2=pat.length();

	if(len1<len2)
	{
		return "NO Window";
	}

	int hash_str[256]={0};
	int hash_pat[256]={0};

	for (int i = 0; i < len2; ++i)
	{
		hash_pat[pat[i]]+=1;
	}

	int start=0, start_index=-1, min_len=INT_MAX, count=0;

	for (int j = 0; j < len1; ++j)
	{
		hash_str[str[j]]++;
		if(hash_pat[str[j]]!=0 and hash_str[str[j]]<=hash_pat[str[j]])
		{
			count+=1;
		}

		if(count == len2)
		{
			while(hash_str[str[start]]> hash_pat[str[start]] or hash_pat[str[start]]==0)
			{
				if(hash_str[str[start]]> hash_pat[str[start]])
				{
					hash_str[str[start]]-=1;
				}
				start+=1;
			}

			int len_window= j-start+1;
			if(min_len>len_window)
			{
				min_len = len_window;
				start_index = start;
			}
		}
	}
	if(start_index==-1)
	{
		return "No Window";
	}
	return str.substr(start_index,min_len);
}

int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<minWindowsubstring(s1,s2)<<endl;
	
	return 0;
}